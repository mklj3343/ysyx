/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include "common.h"
#include <difftest-def.h>
#include <sys/prctl.h>
#include <signal.h>

bool gdb_connect_qemu(int port);                          // 连接到 QEMU 的 GDB 调试端口
bool gdb_memcpy_to_qemu(uint32_t addr, void *buf, int n); // 将数据从主机复制到 QEMU 内存
bool gdb_getregs(union isa_gdb_regs *regs);               // 获取 QEMU 的寄存器状态
bool gdb_setregs(union isa_gdb_regs *regs);               // 设置 QEMU 的寄存器状态
bool gdb_si();                                            // 执行 QEMU 单步指令
void gdb_exit();                                          // 退出 QEMU 的 GDB 调试连接
void init_isa();                                          // 初始化指令集体系结构（ISA）相关设置

void init_isa();

// 将内存数据复制到参考实现（QEMU）
// direction: 数据传输方向（DIFFTEST_TO_REF 表示主机到 QEMU）
__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  assert(direction == DIFFTEST_TO_REF); 
  if (direction == DIFFTEST_TO_REF) {
    bool ok = gdb_memcpy_to_qemu(addr, buf, n);
    assert(ok == 1);
  }
}

// 复制寄存器状态（主机与 QEMU 之间）
__EXPORT void difftest_regcpy(void *dut, bool direction) {
  union isa_gdb_regs qemu_r;
  // qemu_r: 存储 QEMU 的寄存器状态
  gdb_getregs(&qemu_r);
  if (direction == DIFFTEST_TO_REF) {
    memcpy(&qemu_r, dut, DIFFTEST_REG_SIZE); // 将主机寄存器数据复制到 qemu_r
    gdb_setregs(&qemu_r);                    // 更新 QEMU 的寄存器状态
  } else {
    memcpy(dut, &qemu_r, DIFFTEST_REG_SIZE);
  }
}

// 执行指定数量的指令
__EXPORT void difftest_exec(uint64_t n) {
  while (n --) gdb_si();
}

// 初始化差分测试环境
__EXPORT void difftest_init(int port) {
  char buf[32];
  sprintf(buf, "tcp::%d", port); // 格式化端口号为 TCP 地址

  int ppid_before_fork = getpid();
  int pid = fork(); // 创建子进程
  if (pid == -1) {
    perror("fork");
    assert(0);
  }
  else if (pid == 0) {
    // child

    // install a parent death signal in the chlid
    // 设置父进程死亡时向子进程发送 SIGTERM 信号
    int r = prctl(PR_SET_PDEATHSIG, SIGTERM);
    if (r == -1) {
      perror("prctl error");
      assert(0);
    }

    // 检查父进程是否已退出
    if (getppid() != ppid_before_fork) {
      printf("parent has died!\n");
      assert(0);
    }

    close(STDIN_FILENO); // 关闭子进程的标准输入
    // 执行 QEMU 程序，启用 GDB 调试模式
    execlp(ISA_QEMU_BIN, ISA_QEMU_BIN, ISA_QEMU_ARGS "-S", "-gdb", buf, "-nographic",
        "-serial", "none", "-monitor", "none", NULL);

    // ISA_QEMU_BIN: QEMU 可执行文件的路径
    // ISA_QEMU_ARGS: QEMU 的额外参数
    // "-S": QEMU 启动后暂停，等待 GDB 连接
    // "-gdb": 指定 GDB 调试的 TCP 地址
    // "-nographic": 禁用图形界面
    // "-serial none": 禁用串口
    // "-monitor none": 禁用监控接口
    perror("exec");
    assert(0);
  }
  else {
    // father
    // 父进程逻辑

    gdb_connect_qemu(port); // 连接到 QEMU 的 GDB 调试端口
    printf("Connect to QEMU with %s successfully\n", buf);

    atexit(gdb_exit); // 注册程序退出时调用 gdb_exit() 清理 GDB 连接

    init_isa();
  }
}

// 触发中断（当前未实现）
__EXPORT void difftest_raise_intr(uint64_t NO) {
  printf("raise_intr is not supported\n");
  assert(0);
}
