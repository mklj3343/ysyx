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

\ // conn: 全局静态变量，存储与 QEMU 的 GDB 连接对象
static struct gdb_conn *conn;

bool gdb_connect_qemu(int port) {
  // connect to gdbserver on localhost port 1234
  while ((conn = gdb_begin_inet("127.0.0.1", port)) == NULL) {
    usleep(1); // 如果连接失败，等待 1 微秒后重试
  }

  return true;
}

// 向 QEMU 内存写入小块数据的辅助函数
static bool gdb_memcpy_to_qemu_small(uint32_t dest, void *src, int len) {
  // 每个字节需要两个十六进制字符表示，因此分配 len * 2 + 额外空间,一个字符只能表示4位（二进制），一个字节（byte）包含8位，所以一个字节需要两个十六进制字符来完全表示。
  char *buf = malloc(len * 2 + 128);
  assert(buf != NULL);
  // 构造 GDB 内存写入命令头，例如 "M0x1000,10:"
  int p = sprintf(buf, "M0x%x,%x:", dest, len);
  int i;
  for (i = 0; i < len; i ++) {
    p += sprintf(buf + p, "%c%c", hex_encode(((uint8_t *)src)[i] >> 4), hex_encode(((uint8_t *)src)[i] & 0xf)); // 高低 4 位转十六进制
  }

  // 发送 GDB 命令到 QEMU
  gdb_send(conn, (const uint8_t *)buf, strlen(buf));
  free(buf);

  size_t size;
  uint8_t *reply = gdb_recv(conn, &size);
  bool ok = !strcmp((const char *)reply, "OK");
  // 检查响应是否为 "OK" 
  free(reply);

  return ok;
}
// 向 QEMU 内存写入数据的接口，支持分块传输
bool gdb_memcpy_to_qemu(uint32_t dest, void *src, int len) {
  const int mtu = 1500; // mtu: 最大传输单元，限制单次传输大小为 1500 字节
  bool ok = true;
  // 如果数据长度超过 MTU，分块传输
  while (len > mtu) {
    ok &= gdb_memcpy_to_qemu_small(dest, src, mtu); // 传输一块数据
    dest += mtu;
    src += mtu;
    len -= mtu;
  }
  ok &= gdb_memcpy_to_qemu_small(dest, src, len); // 传输剩余的数据（小于等于 MTU）
  return ok;
}
// 获取 QEMU 的寄存器状态
bool gdb_getregs(union isa_gdb_regs *r) {
  gdb_send(conn, (const uint8_t *)"g", 1);
  size_t size;
  uint8_t *reply = gdb_recv(conn, &size); // 接收 QEMU 的响应（寄存器值的十六进制字符串）

  int i;
  uint8_t *p = reply;
  uint8_t c;
  for (i = 0; i < sizeof(union isa_gdb_regs) / sizeof(uint32_t); i ++) {
    c = p[8];
    p[8] = '\0'; // 临时截断字符串，便于解析
    r->array[i] = gdb_decode_hex_str(p); // 解析 8 个字符为 32 位寄存器值
    p[8] = c;
    p += 8;
  }

  free(reply);

  return true;
}

// 设置 QEMU 的寄存器状态
bool gdb_setregs(union isa_gdb_regs *r) {
  // 计算寄存器数据的总字节数
  int len = sizeof(union isa_gdb_regs);
  char *buf = malloc(len * 2 + 128); // 分配缓冲区，用于构造 GDB 设置寄存器命令（格式为 "G<数据>"）
  assert(buf != NULL);
  buf[0] = 'G'; // 设置命令头为 "G"

  // 将寄存器数据转换为十六进制格式
  void *src = r;
  int p = 1;
  int i;
  for (i = 0; i < len; i ++) {
    p += sprintf(buf + p, "%c%c", hex_encode(((uint8_t *)src)[i] >> 4), hex_encode(((uint8_t *)src)[i] & 0xf));
  }

  gdb_send(conn, (const uint8_t *)buf, strlen(buf));
  free(buf);

  size_t size;
  uint8_t *reply = gdb_recv(conn, &size);
  bool ok = !strcmp((const char*)reply, "OK");
  free(reply);

  return ok;
}

bool gdb_si() {
  char buf[] = "vCont;s:1";
  gdb_send(conn, (const uint8_t *)buf, strlen(buf));
  size_t size;
  uint8_t *reply = gdb_recv(conn, &size);
  free(reply);
  return true;
}

void gdb_exit() {
  gdb_end(conn);
}
