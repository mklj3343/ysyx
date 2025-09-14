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
    // DPI import at /home/zxj17/ysyx-workbench/npc/vsrc/ysyx_25040109_top.v:89:34
    extern void itrace_print(int pc, int instruction_word, int instr_len_bytes, int p_count_number);
    // DPI import at /home/zxj17/ysyx-workbench/npc/vsrc/ysyx_25040109_top.v:90:34
    extern void printf_finish();
    // DPI import at /home/zxj17/ysyx-workbench/npc/vsrc/regfile.v:25:34
    extern void update_cpu_state(int pc, const svOpenArrayHandle regs);
    // DPI import at /home/zxj17/ysyx-workbench/npc/vsrc/ysyx_25040109_top.v:88:34
    extern void update_decode_state(int pc, int snpc, int dnpc, int inst);
    // DPI import at /home/zxj17/ysyx-workbench/npc/vsrc/ifu_mem.v:12:33
    extern int verilog_pmem_read(int addr, int len);
    // DPI import at /home/zxj17/ysyx-workbench/npc/vsrc/lsu_mem.v:15:34
    extern void verilog_pmem_write(int addr, int data, int len);

#ifdef __cplusplus
}
#endif

#endif  // guard
