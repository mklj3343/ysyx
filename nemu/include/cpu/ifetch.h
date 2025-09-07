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

#ifndef __CPU_IFETCH_H__
#define __CPU_IFETCH_H__

#include <memory/vaddr.h>
extern void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);

static inline uint32_t inst_fetch(vaddr_t *pc, int len) {

  uint32_t inst = vaddr_ifetch(*pc, len);

  (*pc) += len;

  // vaddr_t orig_pc = *pc;
  /*char disasm_str[64];
  disassemble(disasm_str, sizeof(disasm_str), orig_pc, (uint8_t *)&inst, len);
  log_write("0x%x: %08x %s\n", orig_pc, inst, disasm_str);
*/

  return inst;
}

#endif
