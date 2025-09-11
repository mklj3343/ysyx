// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VYSYX_25040109_TOP__DPI_H_
#define VERILATED_VYSYX_25040109_TOP__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/zxj17/ysyx-workbench/npc/vsrc/ysyx_25040109_top.v:72:34
    extern void itrace_print(int pc, int instruction_word, int instr_len_bytes, int p_count_number);
    // DPI import at /home/zxj17/ysyx-workbench/npc/vsrc/ysyx_25040109_top.v:73:34
    extern void printf_finish();
    // DPI import at /home/zxj17/ysyx-workbench/npc/vsrc/ysyx_25040109_RegisterFile.v:55:34
    extern void update_cpu_state(unsigned int pc, const svOpenArrayHandle regs);
    // DPI import at /home/zxj17/ysyx-workbench/npc/vsrc/ysyx_25040109_top.v:71:34
    extern void update_decode_state(int pc, int snpc, int dnpc, int inst);
    // DPI import at /home/zxj17/ysyx-workbench/npc/vsrc/ysyx_25040109_mem.v:20:33
    extern int verilog_pmem_read(int addr);
    // DPI import at /home/zxj17/ysyx-workbench/npc/vsrc/ysyx_25040109_mem.v:21:34
    extern void verilog_pmem_write(int addr, int data, char mask);

#ifdef __cplusplus
}
#endif

#endif  // guard
