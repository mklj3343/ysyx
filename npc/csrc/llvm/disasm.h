#ifndef __DISASM_H__
#define __DISASM_H__

extern "C" void init_disasm_llvm();
extern "C" void free_disasm_llvm();
extern "C" void itrace_print(long long pc, unsigned int instruction_word, int instr_len_bytes, int p_count_number);
#endif