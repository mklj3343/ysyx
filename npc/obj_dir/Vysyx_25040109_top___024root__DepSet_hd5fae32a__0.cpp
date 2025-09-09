// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_25040109_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_25040109_top___024root.h"

void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__mem__DOT__verilog_pmem_read_TOP(IData/*31:0*/ addr, IData/*31:0*/ &data);

VL_INLINE_OPT void Vysyx_25040109_top___024root___ico_sequent__TOP__0(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___ico_sequent__TOP__0\n"); );
    // Body
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
}

void Vysyx_25040109_top___024root___eval_ico(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vysyx_25040109_top___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vysyx_25040109_top___024root___eval_act(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___eval_act\n"); );
}

void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__itrace_print_TOP(IData/*31:0*/ pc, IData/*31:0*/ instruction_word, IData/*31:0*/ instr_len_bytes, IData/*31:0*/ p_count_number);
void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__printf_finish_TOP();
void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__mem__DOT__verilog_pmem_write_TOP(IData/*31:0*/ addr, IData/*31:0*/ data, IData/*31:0*/ len);
void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__update_cpu_state__Vdpioc2_TOP(IData/*31:0*/ pc, const VlUnpacked<IData/*31:0*/, 16> &regs);
void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__update_decode_state_TOP(IData/*31:0*/ pc, IData/*31:0*/ snpc, IData/*31:0*/ dnpc, IData/*31:0*/ inst);

VL_INLINE_OPT void Vysyx_25040109_top___024root___nba_sequent__TOP__0(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    QData/*63:0*/ __Vdly__ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter;
    __Vdly__ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter = 0;
    CData/*3:0*/ __Vdlyvdim0__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0;
    __Vdlyvdim0__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0;
    __Vdlyvval__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0 = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0;
    __Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0 = 0;
    // Body
    Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__itrace_print_TOP(vlSelf->pc, vlSelf->inst, 4U, vlSelf->p_count_number);
    if ((0x100073U == vlSelf->inst)) {
        Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__itrace_print_TOP(vlSelf->pc, vlSelf->inst, 4U, vlSelf->p_count_number);
        Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__printf_finish_TOP();
    }
    __Vdly__ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter;
    __Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0 = 0U;
    if (((((~ (IData)(vlSelf->rst)) & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state)) 
          & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0)) 
         & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store))) {
        vlSelf->ysyx_25040109_top__DOT__mem__DOT__unnamedblk1__DOT__len 
            = ((0U == (7U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                             >> 0xcU))) ? 1U : ((2U 
                                                 == 
                                                 (7U 
                                                  & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                     >> 0xcU)))
                                                 ? 4U
                                                 : 0U));
        if (VL_LTS_III(32, 0U, vlSelf->ysyx_25040109_top__DOT__mem__DOT__unnamedblk1__DOT__len)) {
            Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__mem__DOT__verilog_pmem_write_TOP(vlSelf->ysyx_25040109_top__DOT__mem_addr, vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata2_reg, vlSelf->ysyx_25040109_top__DOT__mem__DOT__unnamedblk1__DOT__len);
        }
    }
    if (vlSelf->rst) {
        __Vdly__ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter = 0ULL;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata1_reg = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current = 0x80000000U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata2_reg = 0U;
    } else {
        __Vdly__ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter 
            = (1ULL + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter);
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata1_reg 
            = ((0U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__raddr1))
                ? 0U : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf
               [(0xfU & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__raddr1))]);
        if (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state) {
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current 
                = vlSelf->ysyx_25040109_top__DOT__next_pc_internal;
        }
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata2_reg 
            = ((0U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__raddr2))
                ? 0U : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf
               [(0xfU & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__raddr2))]);
    }
    if (((((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state) 
           & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0) 
              & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu__DOT____VdfgTmp_h250803ec__0) 
                 | (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw)))) 
          & (0U != (0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                             >> 7U)))) & (0xfU >= (0x1fU 
                                                   & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                      >> 7U))))) {
        __Vdlyvval__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0 
            = ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw)
                ? ((0xb00U == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                               >> 0x14U)) ? (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter)
                    : ((0xb80U == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                   >> 0x14U)) ? (IData)(
                                                        (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter 
                                                         >> 0x20U))
                        : ((0xf11U == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                       >> 0x14U)) ? 0x79737978U
                            : ((0xf12U == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                           >> 0x14U))
                                ? 0x17e14edU : 0U))))
                : ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load)
                    ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__load_data
                    : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result));
        __Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0 = 1U;
        __Vdlyvdim0__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0 
            = (0xfU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                       >> 7U));
    }
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter 
        = __Vdly__ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter;
    if ((1U & ((~ (IData)(vlSelf->rst)) & (~ (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state))))) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
            = vlSelf->ysyx_25040109_top__DOT__mem__DOT__mem_rdata_reg;
    }
    vlSelf->pc = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current;
    if (__Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[__Vdlyvdim0__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0] 
            = __Vdlyvval__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0;
    }
    Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__update_cpu_state__Vdpioc2_TOP(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current, vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf);
    vlSelf->a0_out = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf
        [0xaU];
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state 
        = ((~ (IData)(vlSelf->rst)) & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__next_state));
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
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__next_state 
        = (1U & (~ (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state)));
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

void Vysyx_25040109_top___024root___eval_nba(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vysyx_25040109_top___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
}

void Vysyx_25040109_top___024root___eval_triggers__ico(Vysyx_25040109_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25040109_top___024root___dump_triggers__ico(Vysyx_25040109_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vysyx_25040109_top___024root___eval_triggers__act(Vysyx_25040109_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25040109_top___024root___dump_triggers__act(Vysyx_25040109_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25040109_top___024root___dump_triggers__nba(Vysyx_25040109_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_25040109_top___024root___eval(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vysyx_25040109_top___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vysyx_25040109_top___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/zxj17/ysyx-workbench/npc/vsrc/ysyx_25040109_top.v", 4, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vysyx_25040109_top___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vysyx_25040109_top___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vysyx_25040109_top___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/zxj17/ysyx-workbench/npc/vsrc/ysyx_25040109_top.v", 4, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vysyx_25040109_top___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vysyx_25040109_top___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/zxj17/ysyx-workbench/npc/vsrc/ysyx_25040109_top.v", 4, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vysyx_25040109_top___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vysyx_25040109_top___024root___eval_debug_assertions(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
