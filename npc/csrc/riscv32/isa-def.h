#ifndef __ISA_RISCV_H__
#define __ISA_RISCV_H__

#include <common.h>


typedef struct
{
    word_t gpr [32];
    vaddr_t pc;
} riscv32_CPU_state;


typedef struct
{
    uint32_t inst;
} riscv32_ISADecodeInfo;

#define isa_mmu_check(vaddr, len, type) (MMU_DIRECT)

#endif