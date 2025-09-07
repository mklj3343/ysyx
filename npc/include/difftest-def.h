
#ifndef __DIFFTEST_DEF_H__
#define __DIFFTEST_DEF_H__

#include<stdint.h>
#include<macro.h>
#include<generated/autoconf.h>


#define __EXPORT __attribute((visibility("default")))

enum
{
    DIFFTEST_TO_DUT,
    DIFFTEST_TO_REF
};

// RISC-V 架构下 GPR 的数据类型
#define RISCV_GPB_TYPE uint32_t
#define RISCv_GPB_NUM 32
#define DIFFTEST_REG_SIZE (sizeof(RISCV_GPB_TYPE) * (RISCv_GPB_NUM + 1))

#endif