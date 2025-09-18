// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_25040109_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_25040109_top__Syms.h"
#include "Vysyx_25040109_top___024root.h"

extern "C" void update_decode_state(int pc, int snpc, int dnpc, int inst);

VL_INLINE_OPT void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__update_decode_state_TOP(IData/*31:0*/ pc, IData/*31:0*/ snpc, IData/*31:0*/ dnpc, IData/*31:0*/ inst) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__update_decode_state_TOP\n"); );
    // Body
    int pc__Vcvt;
    for (size_t pc__Vidx = 0; pc__Vidx < 1; ++pc__Vidx) pc__Vcvt = pc;
    int snpc__Vcvt;
    for (size_t snpc__Vidx = 0; snpc__Vidx < 1; ++snpc__Vidx) snpc__Vcvt = snpc;
    int dnpc__Vcvt;
    for (size_t dnpc__Vidx = 0; dnpc__Vidx < 1; ++dnpc__Vidx) dnpc__Vcvt = dnpc;
    int inst__Vcvt;
    for (size_t inst__Vidx = 0; inst__Vidx < 1; ++inst__Vidx) inst__Vcvt = inst;
    update_decode_state(pc__Vcvt, snpc__Vcvt, dnpc__Vcvt, inst__Vcvt);
}

extern "C" void itrace_print(int pc, int instruction_word, int instr_len_bytes, int p_count_number);

VL_INLINE_OPT void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__itrace_print_TOP(IData/*31:0*/ pc, IData/*31:0*/ instruction_word, IData/*31:0*/ instr_len_bytes, IData/*31:0*/ p_count_number) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__itrace_print_TOP\n"); );
    // Body
    int pc__Vcvt;
    for (size_t pc__Vidx = 0; pc__Vidx < 1; ++pc__Vidx) pc__Vcvt = pc;
    int instruction_word__Vcvt;
    for (size_t instruction_word__Vidx = 0; instruction_word__Vidx < 1; ++instruction_word__Vidx) instruction_word__Vcvt = instruction_word;
    int instr_len_bytes__Vcvt;
    for (size_t instr_len_bytes__Vidx = 0; instr_len_bytes__Vidx < 1; ++instr_len_bytes__Vidx) instr_len_bytes__Vcvt = instr_len_bytes;
    int p_count_number__Vcvt;
    for (size_t p_count_number__Vidx = 0; p_count_number__Vidx < 1; ++p_count_number__Vidx) p_count_number__Vcvt = p_count_number;
    itrace_print(pc__Vcvt, instruction_word__Vcvt, instr_len_bytes__Vcvt, p_count_number__Vcvt);
}

extern "C" void printf_finish();

VL_INLINE_OPT void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__printf_finish_TOP() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__printf_finish_TOP\n"); );
    // Body
    printf_finish();
}

extern "C" void update_cpu_state16(int pc, int r0, int r1, int r2, int r3, int r4, int r5, int r6, int r7, int r8, int r9, int r10, int r11, int r12, int r13, int r14, int r15);

VL_INLINE_OPT void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__update_cpu_state16_TOP(IData/*31:0*/ pc, IData/*31:0*/ r0, IData/*31:0*/ r1, IData/*31:0*/ r2, IData/*31:0*/ r3, IData/*31:0*/ r4, IData/*31:0*/ r5, IData/*31:0*/ r6, IData/*31:0*/ r7, IData/*31:0*/ r8, IData/*31:0*/ r9, IData/*31:0*/ r10, IData/*31:0*/ r11, IData/*31:0*/ r12, IData/*31:0*/ r13, IData/*31:0*/ r14, IData/*31:0*/ r15) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__update_cpu_state16_TOP\n"); );
    // Body
    int pc__Vcvt;
    for (size_t pc__Vidx = 0; pc__Vidx < 1; ++pc__Vidx) pc__Vcvt = pc;
    int r0__Vcvt;
    for (size_t r0__Vidx = 0; r0__Vidx < 1; ++r0__Vidx) r0__Vcvt = r0;
    int r1__Vcvt;
    for (size_t r1__Vidx = 0; r1__Vidx < 1; ++r1__Vidx) r1__Vcvt = r1;
    int r2__Vcvt;
    for (size_t r2__Vidx = 0; r2__Vidx < 1; ++r2__Vidx) r2__Vcvt = r2;
    int r3__Vcvt;
    for (size_t r3__Vidx = 0; r3__Vidx < 1; ++r3__Vidx) r3__Vcvt = r3;
    int r4__Vcvt;
    for (size_t r4__Vidx = 0; r4__Vidx < 1; ++r4__Vidx) r4__Vcvt = r4;
    int r5__Vcvt;
    for (size_t r5__Vidx = 0; r5__Vidx < 1; ++r5__Vidx) r5__Vcvt = r5;
    int r6__Vcvt;
    for (size_t r6__Vidx = 0; r6__Vidx < 1; ++r6__Vidx) r6__Vcvt = r6;
    int r7__Vcvt;
    for (size_t r7__Vidx = 0; r7__Vidx < 1; ++r7__Vidx) r7__Vcvt = r7;
    int r8__Vcvt;
    for (size_t r8__Vidx = 0; r8__Vidx < 1; ++r8__Vidx) r8__Vcvt = r8;
    int r9__Vcvt;
    for (size_t r9__Vidx = 0; r9__Vidx < 1; ++r9__Vidx) r9__Vcvt = r9;
    int r10__Vcvt;
    for (size_t r10__Vidx = 0; r10__Vidx < 1; ++r10__Vidx) r10__Vcvt = r10;
    int r11__Vcvt;
    for (size_t r11__Vidx = 0; r11__Vidx < 1; ++r11__Vidx) r11__Vcvt = r11;
    int r12__Vcvt;
    for (size_t r12__Vidx = 0; r12__Vidx < 1; ++r12__Vidx) r12__Vcvt = r12;
    int r13__Vcvt;
    for (size_t r13__Vidx = 0; r13__Vidx < 1; ++r13__Vidx) r13__Vcvt = r13;
    int r14__Vcvt;
    for (size_t r14__Vidx = 0; r14__Vidx < 1; ++r14__Vidx) r14__Vcvt = r14;
    int r15__Vcvt;
    for (size_t r15__Vidx = 0; r15__Vidx < 1; ++r15__Vidx) r15__Vcvt = r15;
    update_cpu_state16(pc__Vcvt, r0__Vcvt, r1__Vcvt, r2__Vcvt, r3__Vcvt, r4__Vcvt, r5__Vcvt, r6__Vcvt, r7__Vcvt, r8__Vcvt, r9__Vcvt, r10__Vcvt, r11__Vcvt, r12__Vcvt, r13__Vcvt, r14__Vcvt, r15__Vcvt);
}

extern "C" int verilog_pmem_read(int addr, int len);

VL_INLINE_OPT void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__ifu_mem_inst__DOT__verilog_pmem_read_TOP(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ &verilog_pmem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__ifu_mem_inst__DOT__verilog_pmem_read_TOP\n"); );
    // Body
    int addr__Vcvt;
    for (size_t addr__Vidx = 0; addr__Vidx < 1; ++addr__Vidx) addr__Vcvt = addr;
    int len__Vcvt;
    for (size_t len__Vidx = 0; len__Vidx < 1; ++len__Vidx) len__Vcvt = len;
    int verilog_pmem_read__Vfuncrtn__Vcvt;
    verilog_pmem_read__Vfuncrtn__Vcvt = verilog_pmem_read(addr__Vcvt, len__Vcvt);
    verilog_pmem_read__Vfuncrtn = verilog_pmem_read__Vfuncrtn__Vcvt;
}

extern "C" void verilog_pmem_write(int addr, int data, int len);

VL_INLINE_OPT void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_write_TOP(IData/*31:0*/ addr, IData/*31:0*/ data, IData/*31:0*/ len) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_write_TOP\n"); );
    // Body
    int addr__Vcvt;
    for (size_t addr__Vidx = 0; addr__Vidx < 1; ++addr__Vidx) addr__Vcvt = addr;
    int data__Vcvt;
    for (size_t data__Vidx = 0; data__Vidx < 1; ++data__Vidx) data__Vcvt = data;
    int len__Vcvt;
    for (size_t len__Vidx = 0; len__Vidx < 1; ++len__Vidx) len__Vcvt = len;
    verilog_pmem_write(addr__Vcvt, data__Vcvt, len__Vcvt);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25040109_top___024root___dump_triggers__act(Vysyx_25040109_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_25040109_top___024root___eval_triggers__act(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = (((IData)(vlSelf->clk) 
                                       & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk))) 
                                      | ((IData)(vlSelf->rst) 
                                         & (~ (IData)(vlSelf->__Vtrigrprev__TOP__rst))));
    vlSelf->__VactTriggered.at(1U) = ((~ (IData)(vlSelf->clk)) 
                                      & (IData)(vlSelf->__Vtrigrprev__TOP__clk));
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__rst = vlSelf->rst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vysyx_25040109_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}
