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
                VL_FATAL_MT("/home/zxj17/ysyx-workbench/npc/vsrc/ysyx_25040109_top.v", 4, "", "Settle region did not converge.");
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

void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__update_cpu_state__Vdpioc2_TOP(IData/*31:0*/ pc, const VlUnpacked<IData/*31:0*/, 16> &regs);
void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__update_decode_state_TOP(IData/*31:0*/ pc, IData/*31:0*/ snpc, IData/*31:0*/ dnpc, IData/*31:0*/ inst);
void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__mem__DOT__verilog_pmem_read_TOP(IData/*31:0*/ addr, IData/*31:0*/ &data);

VL_ATTR_COLD void Vysyx_25040109_top___024root___stl_sequent__TOP__0(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___stl_sequent__TOP__0\n"); );
    // Body
    Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__update_cpu_state__Vdpioc2_TOP(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current, vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__next_state 
        = (1U & (~ (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state)));
    vlSelf->a0_out = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf
        [0xaU];
    vlSelf->pc = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current;
    vlSelf->inst = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw 
        = ((0x73U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)) 
           & ((1U == (7U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                            >> 0xcU))) | (2U == (7U 
                                                 & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                    >> 0xcU)))));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load 
        = ((3U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)) 
           & ((2U == (7U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                            >> 0xcU))) | (4U == (7U 
                                                 & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                    >> 0xcU)))));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_jalr 
        = (IData)((0x67U == (0x707fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store 
        = ((0x23U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)) 
           & ((2U == (7U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                            >> 0xcU))) | (0U == (7U 
                                                 & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                    >> 0xcU)))));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_add 
        = (IData)((0x33U == (0xfe00707fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu__DOT____VdfgTmp_h250803ec__0 
        = ((0x37U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)) 
           | ((IData)((0x13U == (0x707fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg))) 
              | ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_add) 
                 | ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_jalr) 
                    | (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load)))));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu__DOT__alu_out 
        = (((0x37U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg))
             ? 0U : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata1_reg) 
           + ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_add)
               ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata2_reg
               : ((0x37U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg))
                   ? (0xfffff000U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)
                   : ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store)
                       ? (((- (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                       >> 0x1fU))) 
                           << 0xcU) | ((0xfe0U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                  >> 0x14U)) 
                                       | (0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                   >> 7U))))
                       : (((- (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                       >> 0x1fU))) 
                           << 0xcU) | (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                       >> 0x14U))))));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0 
        = ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu__DOT____VdfgTmp_h250803ec__0) 
           | ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store) 
              | (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw)));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result 
        = ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_jalr)
            ? ((IData)(4U) + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current)
            : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu__DOT__alu_out);
    Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__update_decode_state_TOP(vlSelf->pc, 
                                                                                ((IData)(4U) 
                                                                                + vlSelf->pc), 
                                                                                ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0)
                                                                                 ? 
                                                                                ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_jalr)
                                                                                 ? 
                                                                                (0xfffffffeU 
                                                                                & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu__DOT__alu_out)
                                                                                 : 
                                                                                ((IData)(4U) 
                                                                                + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current))
                                                                                 : 
                                                                                ((IData)(4U) 
                                                                                + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current)), vlSelf->inst);
    vlSelf->ysyx_25040109_top__DOT__next_pc_internal 
        = ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0)
            ? ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_jalr)
                ? (0xfffffffeU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu__DOT__alu_out)
                : ((IData)(4U) + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current))
            : ((IData)(4U) + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current));
    vlSelf->ysyx_25040109_top__DOT__mem_addr = ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state)
                                                 ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result
                                                 : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current);
    if (((~ (IData)(vlSelf->rst)) & (((~ (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state)) 
                                      | ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state) 
                                         & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0) 
                                            & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load)))) 
                                     & (0U != vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current)))) {
        Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__mem__DOT__verilog_pmem_read_TOP(vlSelf->ysyx_25040109_top__DOT__mem_addr, vlSelf->__Vtask_ysyx_25040109_top__DOT__mem__DOT__verilog_pmem_read__5__data);
        vlSelf->ysyx_25040109_top__DOT__mem__DOT__mem_rdata_reg 
            = vlSelf->__Vtask_ysyx_25040109_top__DOT__mem__DOT__verilog_pmem_read__5__data;
    } else {
        vlSelf->ysyx_25040109_top__DOT__mem__DOT__mem_rdata_reg = 0U;
    }
    if (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__raddr1 
            = (0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                        >> 0xfU));
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__raddr2 
            = (0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                        >> 0x14U));
    } else {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__raddr1 
            = (0x1fU & (vlSelf->ysyx_25040109_top__DOT__mem__DOT__mem_rdata_reg 
                        >> 0xfU));
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__raddr2 
            = (0x1fU & (vlSelf->ysyx_25040109_top__DOT__mem__DOT__mem_rdata_reg 
                        >> 0x14U));
    }
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__load_data = 0U;
    if ((2U == (7U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                      >> 0xcU)))) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__load_data 
            = vlSelf->ysyx_25040109_top__DOT__mem__DOT__mem_rdata_reg;
    } else if ((4U == (7U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                             >> 0xcU)))) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__load_data 
            = (0xffU & vlSelf->ysyx_25040109_top__DOT__mem__DOT__mem_rdata_reg);
    }
}

VL_ATTR_COLD void Vysyx_25040109_top___024root___eval_stl(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vysyx_25040109_top___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25040109_top___024root___dump_triggers__ico(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

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
    vlSelf->ysyx_25040109_top__DOT__mem_addr = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__next_pc_internal = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__next_state = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__load_data = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_add = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_jalr = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter = VL_RAND_RESET_Q(64);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__raddr1 = VL_RAND_RESET_I(5);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__raddr2 = VL_RAND_RESET_I(5);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0 = 0;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu__DOT____VdfgTmp_h250803ec__0 = 0;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu__DOT__alu_out = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata1_reg = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata2_reg = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__mem__DOT__mem_rdata_reg = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040109_top__DOT__mem__DOT__unnamedblk1__DOT__len = VL_RAND_RESET_I(32);
    vlSelf->__Vtask_ysyx_25040109_top__DOT__mem__DOT__verilog_pmem_read__5__data = 0;
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
