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

#ifndef __DIFFTEST_DEF_H__
#define __DIFFTEST_DEF_H__

#include <stdint.h>
#include <macro.h>
#include <generated/autoconf.h>

// 定义 __EXPORT 宏，用于控制符号的可见性
// __attribute__((visibility("default"))) 确保函数或变量在动态链接库中对外可见
#define __EXPORT __attribute__((visibility("default")))

// DIFFTEST_TO_DUT: 数据从参考实现（QEMU）传输到待测试设备（Device Under Test）
// DIFFTEST_TO_REF: 数据从待测试设备传输到参考实现（QEMU）
enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

#if defined(CONFIG_ISA_x86)
# define DIFFTEST_REG_SIZE (sizeof(uint32_t) * 9) // GPRs + pc
#elif defined(CONFIG_ISA_mips32)
# define DIFFTEST_REG_SIZE (sizeof(uint32_t) * 38) // GPRs + status + lo + hi + badvaddr + cause + pc
#elif defined(CONFIG_ISA_riscv)
#define RISCV_GPR_TYPE MUXDEF(CONFIG_RV64, uint64_t, uint32_t)
#define RISCV_GPR_NUM  MUXDEF(CONFIG_RVE , 16, 32)
#define DIFFTEST_REG_SIZE (sizeof(RISCV_GPR_TYPE) * (RISCV_GPR_NUM + 1)) // GPRs + pc
#elif defined(CONFIG_ISA_loongarch32r)
# define DIFFTEST_REG_SIZE (sizeof(uint32_t) * 33) // GPRs + pc
#else
# error Unsupport ISA
#endif

#endif
