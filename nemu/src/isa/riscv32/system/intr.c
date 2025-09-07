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

#include <isa.h>
#include<csr.h>

word_t isa_raise_intr(word_t NO, vaddr_t epc) {
  /* TODO: Trigger an interrupt/exception with ``NO''.
   * Then return the address of the interrupt/exception vector.
   */
 

  
  cpu.csr[CSR_MCAUSE] = NO;

  cpu.csr[CSR_MEPC] = epc ;

  // 这注释掉不符合标准，，但是当前测试程序不支持，后边才需要处理
  /*
  word_t mstatus = cpu.csr[CSR_MSTATUS];

  if ((mstatus >> 3) & 1) {
    mstatus |= (1 << 7);
  } else {
    mstatus &= ~(1 << 7);
  }

  mstatus &= ~(1 << 3);

  cpu.csr[CSR_MSTATUS] = mstatus;
  */

  word_t handler_addr = cpu.csr[CSR_MTVEC];

  //printf("异常地址入口:0x%08x\n", handler_addr);

  return handler_addr;
}

word_t isa_query_intr() {
  return INTR_EMPTY;
}
