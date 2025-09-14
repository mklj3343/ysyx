// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_25040109_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_25040109_top___024root.h"

VL_ATTR_COLD void Vysyx_25040109_top___024root___eval_static(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vysyx_25040109_top___024root___eval_initial(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__rst = vlSelf->rst;
}

VL_ATTR_COLD void Vysyx_25040109_top___024root___eval_final(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vysyx_25040109_top___024root___eval_triggers__stl(Vysyx_25040109_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25040109_top___024root___dump_triggers__stl(Vysyx_25040109_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vysyx_25040109_top___024root___eval_stl(Vysyx_25040109_top___024root* vlSelf);

VL_ATTR_COLD void Vysyx_25040109_top___024root___eval_settle(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vysyx_25040109_top___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vysyx_25040109_top___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/zxj17/ysyx-workbench/npc/vsrc/ysyx_25040109_top.v", 3, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vysyx_25040109_top___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25040109_top___024root___dump_triggers__stl(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__update_decode_state_TOP(IData/*31:0*/ pc, IData/*31:0*/ snpc, IData/*31:0*/ dnpc, IData/*31:0*/ inst);

VL_ATTR_COLD void Vysyx_25040109_top___024root___stl_sequent__TOP__0(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->a0_out = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
        [0xaU];
    vlSelf->pc = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_pc;
    vlSelf->inst = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst;
    Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__update_decode_state_TOP(vlSelf->pc, 
                                                                                ((IData)(4U) 
                                                                                + vlSelf->pc), 
                                                                                ((IData)(4U) 
                                                                                + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc), vlSelf->inst);
}

VL_ATTR_COLD void Vysyx_25040109_top___024root___eval_stl(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vysyx_25040109_top___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25040109_top___024root___dump_triggers__act(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25040109_top___024root___dump_triggers__nba(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_25040109_top___024root___ctor_var_reset(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->pc = VL_RAND_RESET_I(32);
    vlSelf->inst = VL_RAND_RESET_I(32);
    vlSelf->p_count_number = VL_RAND_RESET_I(32);
    vlSelf->a0_out = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__ifu_data = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__ifu_ready = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040109_top__DOT__lsu_addr = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__lsu_wdata = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__lsu_rdata = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__lsu_op = VL_RAND_RESET_I(2);
    vlSelf->ysyx_25040109_top__DOT__lsu_valid = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040109_top__DOT__lsu_ready = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_ifu_ready = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_pc = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_data = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_data = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_addr = VL_RAND_RESET_I(5);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_addr = VL_RAND_RESET_I(5);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rd_addr = VL_RAND_RESET_I(5);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = VL_RAND_RESET_I(4);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op = VL_RAND_RESET_I(2);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_reg_write = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_jalr = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_pc = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_idu_ready = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_addr = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_wdata = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_mem_op = VL_RAND_RESET_I(2);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_valid = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_addr = VL_RAND_RESET_I(5);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_data = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_write = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr = VL_RAND_RESET_I(5);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_data = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_write = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__jump_flag_from_exu = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__jump_addr_from_exu = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_exu__DOT__alu_result = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__idu_exu_pc = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_valid = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_valid = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_addr = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_wdata = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_op = VL_RAND_RESET_I(2);
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__rst = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
