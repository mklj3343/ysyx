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
#include "mmu.h"
#include "sim.h"
#include "../../include/common.h"
#include <difftest-def.h>

// 定义通用寄存器数量，根据CONFIG_RVE配置选择16（RV32E）或32（RV32I）个寄存器
#define NR_GPR MUXDEF(CONFIG_RVE, 16, 32)

// 存储插件设备的地址和抽象设备对象键值对
static std::vector<std::pair<reg_t, abstract_device_t *>> difftest_plugin_devices;
// 存储HTIF（Host-Target Interface）参数，用于主机与目标交互
static std::vector<std::string> difftest_htif_args;
// 初始化内存，包含基地址DRAM_BASE和大小为CONFIG_MSIZE的内存对象
static std::vector<std::pair<reg_t, mem_t *>> difftest_mem(
    1, std::make_pair(reg_t(DRAM_BASE), new mem_t(CONFIG_MSIZE)));
// 调试模块配置，定义调试相关参数
static debug_module_config_t difftest_dm_config = {
    .progbufsize = 2,                    // 程序缓冲区大小
    .max_sba_data_width = 0,             // 系统总线访问数据宽度
    .require_authentication = false,     // 不需要认证
    .abstract_rti = 0,                   // 抽象实时中断
    .support_hasel = true,               // 支持硬件抽象选择
    .support_abstract_csr_access = true, // 支持抽象CSR访问
    .support_abstract_fpr_access = true, // 支持抽象浮点寄存器访问
    .support_haltgroups = true,          // 支持暂停组
    .support_impebreak = true            // 支持隐式断点
};

// 差分测试上下文结构体，存储寄存器状态和程序计数器
struct diff_context_t
{
  word_t gpr[MUXDEF(CONFIG_RVE, 16, 32)]; // 通用寄存器数组，大小由NR_GPR决定
  word_t pc;                              // 程序计数器（PC）
};

// 全局变量：模拟器、处理器和状态对象的指针
static sim_t *s = NULL;       // 模拟器对象
static processor_t *p = NULL; // 处理器对象
static state_t *state = NULL; // 处理器状态对象

// 初始化差分测试，设置处理器和状态
void sim_t::diff_init(int port)
{
  p = get_core("0");      // 获取ID为"0"的处理器核心
  state = p->get_state(); // 获取处理器状态
}

// 执行n步模拟
void sim_t::diff_step(uint64_t n)
{
  //printf("1113\n");
  step(n); // 调用模拟器的step函数，执行n条指令
}

// 获取寄存器状态，存储到差分上下文
void sim_t::diff_get_regs(void *diff_context)
{
  struct diff_context_t *ctx = (struct diff_context_t *)diff_context;
  for (int i = 0; i < NR_GPR; i++)
  {
    ctx->gpr[i] = state->XPR[i]; // 复制通用寄存器值到上下文
  }
  ctx->pc = state->pc; // 复制PC值到上下文
}

// 设置寄存器状态，从差分上下文写入模拟器
void sim_t::diff_set_regs(void *diff_context)
{
  struct diff_context_t *ctx = (struct diff_context_t *)diff_context;
  for (int i = 0; i < NR_GPR; i++)
  {
    state->XPR.write(i, (sword_t)ctx->gpr[i]); // 将上下文中的寄存器值写入模拟器
  }
  state->pc = ctx->pc; // 将上下文中的PC值写入模拟器
}

// 内存复制，从源地址复制n字节数据到目标地址
void sim_t::diff_memcpy(reg_t dest, void *src, size_t n)
{
  mmu_t *mmu = p->get_mmu(); // 获取内存管理单元
  for (size_t i = 0; i < n; i++)
  {
    mmu->store<uint8_t>(dest + i, *((uint8_t *)src + i)); // 逐字节写入内存
  }
}

// 外部C接口，用于差分测试
extern "C"
{
  // 内存复制接口，支持从DUT（被测设备）到参考模型
  __EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction)
  {
    if (direction == DIFFTEST_TO_REF)
    {
      s->diff_memcpy(addr, buf, n); // 调用模拟器的内存复制函数
    }
    else
    {
      assert(0); // 不支持从参考模型到DUT的复制
    }
  }

  // 寄存器复制接口，支持双向同步
  __EXPORT void difftest_regcpy(void *dut, bool direction)
  {
    if (direction == DIFFTEST_TO_REF)
    {
      s->diff_set_regs(dut); // 从DUT写入参考模型
    }
    else
    {
      s->diff_get_regs(dut); // 从参考模型读取到DUT
    }
  }

  // 执行n条指令
  __EXPORT void difftest_exec(uint64_t n)
  {
    s->diff_step(n); // 调用模拟器的step函数
  }

  // 初始化差分测试环境
  __EXPORT void difftest_init(int port)
  {
    difftest_htif_args.push_back(""); // 添加空的HTIF参数
    // 定义ISA字符串，根据配置选择RV64/RV32和扩展
    const char *isa = "RV" MUXDEF(CONFIG_RV64, "64", "32") MUXDEF(CONFIG_RVE, "E", "I") "MAFDC";
    // 配置模拟器参数
    cfg_t cfg(/*default_initrd_bounds=*/std::make_pair((reg_t)0, (reg_t)0),
              /*default_bootargs=*/nullptr,
              /*default_isa=*/isa,
              /*default_priv=*/DEFAULT_PRIV,
              /*default_varch=*/DEFAULT_VARCH,
              /*default_misaligned=*/false,
              /*default_endianness*/ endianness_little,
              /*default_pmpregions=*/16,
              /*default_mem_layout=*/std::vector<mem_cfg_t>(),
              /*default_hartids=*/std::vector<size_t>(1),
              /*default_real_time_clint=*/false,
              /*default_trigger_count=*/4);
    // 创建模拟器对象
    s = new sim_t(&cfg, false,
                  difftest_mem, difftest_plugin_devices, difftest_htif_args,
                  difftest_dm_config, nullptr, false, NULL,
                  false,
                  NULL,
                  true);
    s->diff_init(port); // 初始化模拟器
  }

  // 触发中断
  __EXPORT void difftest_raise_intr(uint64_t NO)
  {
    trap_t t(NO);                      // 创建中断对象
    p->take_trap_public(t, state->pc); // 触发处理器中断
  }
}