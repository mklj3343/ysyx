#ifndef __ISA_H__
#define __ISA_H__


#include<isa-def.h>



typedef riscv32_CPU_state CPU_state;
typedef riscv32_ISADecodeInfo ISADecodeInfo;

// monitor
extern unsigned char isa_logo[];
void init_isa();

// reg
extern CPU_state cpu;


#ifdef __cplusplus
extern "C"{
    
#endif

    void isa_reg_display();
#ifdef __cplusplus
}

#endif


word_t isa_reg_str2val(const char *name, bool *success);

// exec
struct Decode;
int isa_exec_once(struct Decode *s);

// memory
enum
{
    MMU_DIRECT,
    MMU_TRANSLATE,
    MMU_FAIL
};
enum
{
    MEM_TYPE_IFETCH,
    MEM_TYPE_READ,
    MEM_TYPE_WRITE
};
enum
{
    MEM_RET_OK,
    MEM_RET_FAIL,
    MEM_RET_CROSS_PAGE
};
#ifndef isa_mmu_check
int isa_mmu_check(vaddr_t vaddr, int len, int type);
#endif
paddr_t isa_mmu_translate(vaddr_t vaddr, int len, int type);
// 将虚拟地址（vaddr）翻译为物理地址（paddr_t），

// interrupt/exception
vaddr_t isa_raise_intr(word_t NO, vaddr_t epc);
// ：触发 RISC-V 中断或异常，并返回异常处理程序的入口地址。
#define INTR_EMPTY ((word_t) - 1)
// 0xFFFFFFFF,用于表示没有待处理的中断或异常。
word_t isa_query_intr();
// ：查询当前是否有待处理的中断或异常，并返回中断/异常编号

// difftest
bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc);
void isa_difftest_attach();

#endif