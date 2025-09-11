// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_25040109_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_25040109_top___024root.h"

void Vysyx_25040109_top___024root___eval_act(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___eval_act\n"); );
}

void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__itrace_print_TOP(IData/*31:0*/ pc, IData/*31:0*/ instruction_word, IData/*31:0*/ instr_len_bytes, IData/*31:0*/ p_count_number);
void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__printf_finish_TOP();
void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__mem__DOT__verilog_pmem_read_TOP(IData/*31:0*/ addr, IData/*31:0*/ &verilog_pmem_read__Vfuncrtn);
void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__mem__DOT__verilog_pmem_write_TOP(IData/*31:0*/ addr, IData/*31:0*/ data, CData/*7:0*/ mask);
void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__update_cpu_state__Vdpioc2_TOP(IData/*31:0*/ pc, const VlUnpacked<IData/*31:0*/, 16> &regs);
void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__update_decode_state_TOP(IData/*31:0*/ pc, IData/*31:0*/ snpc, IData/*31:0*/ dnpc, IData/*31:0*/ inst);

VL_INLINE_OPT void Vysyx_25040109_top___024root___nba_sequent__TOP__0(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vfunc_ysyx_25040109_top__DOT__mem__DOT__verilog_pmem_read__5__Vfuncout;
    __Vfunc_ysyx_25040109_top__DOT__mem__DOT__verilog_pmem_read__5__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_25040109_top__DOT__mem__DOT__verilog_pmem_read__7__Vfuncout;
    __Vfunc_ysyx_25040109_top__DOT__mem__DOT__verilog_pmem_read__7__Vfuncout = 0;
    QData/*63:0*/ __Vdly__ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter;
    __Vdly__ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter = 0;
    CData/*1:0*/ __Vdly__ysyx_25040109_top__DOT__cpu__DOT__state;
    __Vdly__ysyx_25040109_top__DOT__cpu__DOT__state = 0;
    CData/*0:0*/ __Vdly__ysyx_25040109_top__DOT__cpu__DOT__fetch_en;
    __Vdly__ysyx_25040109_top__DOT__cpu__DOT__fetch_en = 0;
    CData/*3:0*/ __Vdlyvdim0__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0;
    __Vdlyvdim0__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0;
    __Vdlyvval__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0 = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0;
    __Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0 = 0;
    CData/*0:0*/ __Vdly__ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__state;
    __Vdly__ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__state = 0;
    CData/*0:0*/ __Vdly__ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__state;
    __Vdly__ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__state = 0;
    IData/*31:0*/ __Vdly__ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg;
    __Vdly__ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg = 0;
    CData/*0:0*/ __Vdly__ysyx_25040109_top__DOT__ifu_respValid;
    __Vdly__ysyx_25040109_top__DOT__ifu_respValid = 0;
    CData/*0:0*/ __Vdly__ysyx_25040109_top__DOT__lsu_respValid;
    __Vdly__ysyx_25040109_top__DOT__lsu_respValid = 0;
    IData/*31:0*/ __Vdly__ysyx_25040109_top__DOT__ifu_rdata;
    __Vdly__ysyx_25040109_top__DOT__ifu_rdata = 0;
    IData/*31:0*/ __Vdly__ysyx_25040109_top__DOT__lsu_rdata;
    __Vdly__ysyx_25040109_top__DOT__lsu_rdata = 0;
    // Body
    Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__itrace_print_TOP(vlSelf->pc, vlSelf->inst, 4U, vlSelf->p_count_number);
    if ((0x100073U == vlSelf->inst)) {
        Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__itrace_print_TOP(vlSelf->pc, vlSelf->inst, 4U, vlSelf->p_count_number);
        Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__printf_finish_TOP();
    }
    __Vdly__ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter;
    __Vdly__ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__state 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__state;
    __Vdly__ysyx_25040109_top__DOT__cpu__DOT__fetch_en 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__fetch_en;
    __Vdly__ysyx_25040109_top__DOT__cpu__DOT__state 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__state;
    __Vdly__ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg;
    __Vdly__ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__state 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__state;
    __Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0 = 0U;
    __Vdly__ysyx_25040109_top__DOT__lsu_rdata = vlSelf->ysyx_25040109_top__DOT__lsu_rdata;
    __Vdly__ysyx_25040109_top__DOT__ifu_rdata = vlSelf->ysyx_25040109_top__DOT__ifu_rdata;
    __Vdly__ysyx_25040109_top__DOT__ifu_respValid = vlSelf->ysyx_25040109_top__DOT__ifu_respValid;
    __Vdly__ysyx_25040109_top__DOT__lsu_respValid = vlSelf->ysyx_25040109_top__DOT__lsu_respValid;
    if ((((((2U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__state)) 
            & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__reg_write_en) 
               & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hd745c079__0) 
                  & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0)))) 
           | ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_h21df59c1__0) 
              & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0) 
                 & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__reg_write_en)))) 
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
                        : 0U)) : ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load)
                                   ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__load_data
                                   : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result));
        __Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0 = 1U;
        __Vdlyvdim0__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0 
            = (0xfU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                       >> 7U));
    }
    __Vdly__ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter 
        = ((IData)(vlSelf->rst) ? 0ULL : (1ULL + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter));
    if (vlSelf->rst) {
        __Vdly__ysyx_25040109_top__DOT__ifu_respValid = 0U;
        __Vdly__ysyx_25040109_top__DOT__lsu_respValid = 0U;
    } else {
        __Vdly__ysyx_25040109_top__DOT__ifu_respValid 
            = vlSelf->ysyx_25040109_top__DOT__ifu_reqValid;
        if (vlSelf->ysyx_25040109_top__DOT__ifu_reqValid) {
            Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__mem__DOT__verilog_pmem_read_TOP(vlSelf->ysyx_25040109_top__DOT__ifu_addr, __Vfunc_ysyx_25040109_top__DOT__mem__DOT__verilog_pmem_read__5__Vfuncout);
            __Vdly__ysyx_25040109_top__DOT__ifu_rdata 
                = __Vfunc_ysyx_25040109_top__DOT__mem__DOT__verilog_pmem_read__5__Vfuncout;
        }
        __Vdly__ysyx_25040109_top__DOT__lsu_respValid 
            = vlSelf->ysyx_25040109_top__DOT__lsu_reqValid;
        if (vlSelf->ysyx_25040109_top__DOT__lsu_reqValid) {
            if (vlSelf->ysyx_25040109_top__DOT__lsu_wen) {
                Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__mem__DOT__verilog_pmem_write_TOP(vlSelf->ysyx_25040109_top__DOT__lsu_addr, vlSelf->ysyx_25040109_top__DOT__lsu_wdata, (IData)(vlSelf->ysyx_25040109_top__DOT__lsu_wmask));
            } else {
                Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__mem__DOT__verilog_pmem_read_TOP(vlSelf->ysyx_25040109_top__DOT__lsu_addr, __Vfunc_ysyx_25040109_top__DOT__mem__DOT__verilog_pmem_read__7__Vfuncout);
                __Vdly__ysyx_25040109_top__DOT__lsu_rdata 
                    = __Vfunc_ysyx_25040109_top__DOT__mem__DOT__verilog_pmem_read__7__Vfuncout;
            }
        }
    }
    if (vlSelf->rst) {
        __Vdly__ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__state = 0U;
        vlSelf->ysyx_25040109_top__DOT__lsu_reqValid = 0U;
        __Vdly__ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg = 0U;
        __Vdly__ysyx_25040109_top__DOT__cpu__DOT__state = 0U;
        __Vdly__ysyx_25040109_top__DOT__cpu__DOT__fetch_en = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_en = 0U;
        __Vdly__ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__state = 0U;
        vlSelf->ysyx_25040109_top__DOT__ifu_reqValid = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current = 0x80000000U;
    } else {
        if (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__state) {
            if (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__state) {
                vlSelf->ysyx_25040109_top__DOT__lsu_reqValid = 0U;
                vlSelf->ysyx_25040109_top__DOT__lsu_wen = 0U;
                if (vlSelf->ysyx_25040109_top__DOT__lsu_respValid) {
                    if (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load) {
                        __Vdly__ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg 
                            = vlSelf->ysyx_25040109_top__DOT__lsu_rdata;
                    }
                    __Vdly__ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__state = 0U;
                }
            }
        } else if (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_en) {
            vlSelf->ysyx_25040109_top__DOT__lsu_reqValid = 1U;
            vlSelf->ysyx_25040109_top__DOT__lsu_addr 
                = (0xfffffffcU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result);
            vlSelf->ysyx_25040109_top__DOT__lsu_wen 
                = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store;
            if ((0U == (7U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                              >> 0xcU)))) {
                vlSelf->ysyx_25040109_top__DOT__lsu_wdata 
                    = ((0x1fU >= (0x18U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result 
                                           << 3U)))
                        ? (((0U == (0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                             >> 0x14U)))
                             ? 0U : (0xffU & vlSelf->__VdfgTmp_he3bf7288__0)) 
                           << (0x18U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result 
                                        << 3U))) : 0U);
                vlSelf->ysyx_25040109_top__DOT__lsu_wmask 
                    = (0xfU & ((IData)(1U) << (3U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result)));
            } else if ((1U == (7U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                     >> 0xcU)))) {
                vlSelf->ysyx_25040109_top__DOT__lsu_wdata 
                    = ((0x1fU >= (0x10U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result 
                                           << 3U)))
                        ? (((0U == (0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                             >> 0x14U)))
                             ? 0U : (0xffffU & vlSelf->__VdfgTmp_he3bf7288__0)) 
                           << (0x10U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result 
                                        << 3U))) : 0U);
                vlSelf->ysyx_25040109_top__DOT__lsu_wmask 
                    = (0xfU & ((3U >= (2U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result))
                                ? ((IData)(3U) << (2U 
                                                   & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result))
                                : 0U));
            } else {
                vlSelf->ysyx_25040109_top__DOT__lsu_wdata 
                    = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__rs2_data;
                vlSelf->ysyx_25040109_top__DOT__lsu_wmask 
                    = (0xfU & 0xfU);
            }
            __Vdly__ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__state = 1U;
        } else {
            vlSelf->ysyx_25040109_top__DOT__lsu_reqValid = 0U;
        }
        if ((2U & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__state))) {
            if ((1U & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__state))) {
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_en = 0U;
                if (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_done) {
                    if (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load) {
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__load_data 
                            = ((2U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__funct3))
                                ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg
                                : ((4U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__funct3))
                                    ? (0xffU & ((2U 
                                                 & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result)
                                                 ? 
                                                ((1U 
                                                  & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result)
                                                  ? 
                                                 (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg 
                                                  >> 0x18U)
                                                  : 
                                                 (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg 
                                                  >> 0x10U))
                                                 : 
                                                ((1U 
                                                  & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result)
                                                  ? 
                                                 (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg 
                                                  >> 8U)
                                                  : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg)))
                                    : 0U));
                    }
                    __Vdly__ysyx_25040109_top__DOT__cpu__DOT__state = 0U;
                }
            } else if (vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0) {
                if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load) 
                     | (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store))) {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_en = 1U;
                    __Vdly__ysyx_25040109_top__DOT__cpu__DOT__state = 3U;
                } else {
                    __Vdly__ysyx_25040109_top__DOT__cpu__DOT__state = 0U;
                }
            } else {
                __Vdly__ysyx_25040109_top__DOT__cpu__DOT__state = 0U;
            }
        } else if ((1U & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__state))) {
            __Vdly__ysyx_25040109_top__DOT__cpu__DOT__fetch_en = 0U;
            if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__state) 
                 & (IData)(vlSelf->ysyx_25040109_top__DOT__ifu_respValid))) {
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                    = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg;
                __Vdly__ysyx_25040109_top__DOT__cpu__DOT__state = 2U;
            }
        } else {
            __Vdly__ysyx_25040109_top__DOT__cpu__DOT__fetch_en = 1U;
            __Vdly__ysyx_25040109_top__DOT__cpu__DOT__state = 1U;
        }
        if (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__state) {
            if (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__state) {
                vlSelf->ysyx_25040109_top__DOT__ifu_reqValid = 0U;
                if (vlSelf->ysyx_25040109_top__DOT__ifu_respValid) {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                        = vlSelf->ysyx_25040109_top__DOT__ifu_rdata;
                    __Vdly__ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__state = 0U;
                }
            }
        } else if (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__fetch_en) {
            vlSelf->ysyx_25040109_top__DOT__ifu_reqValid = 1U;
            vlSelf->ysyx_25040109_top__DOT__ifu_addr 
                = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current;
            __Vdly__ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__state = 1U;
        } else {
            vlSelf->ysyx_25040109_top__DOT__ifu_reqValid = 0U;
        }
        if ((((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hd745c079__0) 
              & (2U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__state))) 
             | (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_h21df59c1__0))) {
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current 
                = vlSelf->ysyx_25040109_top__DOT__next_pc_internal;
        }
    }
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter 
        = __Vdly__ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter;
    if (__Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[__Vdlyvdim0__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0] 
            = __Vdlyvval__ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf__v0;
    }
    vlSelf->a0_out = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf
        [0xaU];
    vlSelf->ysyx_25040109_top__DOT__lsu_rdata = __Vdly__ysyx_25040109_top__DOT__lsu_rdata;
    vlSelf->ysyx_25040109_top__DOT__lsu_respValid = __Vdly__ysyx_25040109_top__DOT__lsu_respValid;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__state 
        = __Vdly__ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__state;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg 
        = __Vdly__ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_done 
        = ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__state) 
           & (IData)(vlSelf->ysyx_25040109_top__DOT__lsu_respValid));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__funct3 
        = (7U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                 >> 0xcU));
    vlSelf->inst = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg;
    vlSelf->__VdfgTmp_he3bf7288__0 = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf
        [(0xfU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                  >> 0x14U))];
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw 
        = ((0x73U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)) 
           & ((1U == (7U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                            >> 0xcU))) | (2U == (7U 
                                                 & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                    >> 0xcU)))));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__rs1_data 
        = ((0U == (0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                            >> 0xfU))) ? 0U : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf
           [(0xfU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                     >> 0xfU))]);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load 
        = ((3U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)) 
           & ((2U == (7U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                            >> 0xcU))) | (4U == (7U 
                                                 & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                    >> 0xcU)))));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_add 
        = (IData)((0x33U == (0xfe00707fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store 
        = ((0x23U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)) 
           & ((2U == (7U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                            >> 0xcU))) | (0U == (7U 
                                                 & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                    >> 0xcU)))));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_jalr 
        = (IData)((0x67U == (0x707fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)));
    vlSelf->ysyx_25040109_top__DOT__ifu_rdata = __Vdly__ysyx_25040109_top__DOT__ifu_rdata;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__fetch_en 
        = __Vdly__ysyx_25040109_top__DOT__cpu__DOT__fetch_en;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__state 
        = __Vdly__ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__state;
    vlSelf->ysyx_25040109_top__DOT__ifu_respValid = __Vdly__ysyx_25040109_top__DOT__ifu_respValid;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__rs2_data 
        = ((0U == (0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                            >> 0x14U))) ? 0U : vlSelf->__VdfgTmp_he3bf7288__0);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__imm = 
        ((0x37U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg))
          ? (0xfffff000U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)
          : ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store)
              ? (((- (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                              >> 0x1fU))) << 0xcU) 
                 | ((0xfe0U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                               >> 0x14U)) | (0x1fU 
                                             & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                >> 7U))))
              : (((- (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                              >> 0x1fU))) << 0xcU) 
                 | (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                    >> 0x14U))));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu__DOT____VdfgTmp_h250803ec__0 
        = ((0x37U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)) 
           | ((IData)((0x13U == (0x707fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg))) 
              | ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_add) 
                 | ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_jalr) 
                    | (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load)))));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__reg_write_en 
        = ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu__DOT____VdfgTmp_h250803ec__0) 
           | (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0 
        = ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu__DOT____VdfgTmp_h250803ec__0) 
           | ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store) 
              | (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw)));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hd745c079__0 
        = (1U & (~ ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load) 
                    | (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store))));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__state 
        = __Vdly__ysyx_25040109_top__DOT__cpu__DOT__state;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_h21df59c1__0 
        = ((3U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__state)) 
           & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_done));
    Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__update_cpu_state__Vdpioc2_TOP(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current, vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf);
    VL_WRITEF("jalr:0x%08x  next_pc:0x%08x pc+4:0x%08x,rs1_data:%10# , imm:%10#\n\n",
              32,(0xfffffffeU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__imm 
                                 + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__rs1_data)),
              32,((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0)
                   ? ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_jalr)
                       ? (0xfffffffeU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__imm 
                                         + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__rs1_data))
                       : ((IData)(4U) + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current))
                   : ((IData)(4U) + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current)),
              32,((IData)(4U) + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current),
              32,vlSelf->ysyx_25040109_top__DOT__cpu__DOT__rs1_data,
              32,vlSelf->ysyx_25040109_top__DOT__cpu__DOT__imm);
    vlSelf->ysyx_25040109_top__DOT__next_pc_internal 
        = ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0)
            ? ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_jalr)
                ? (0xfffffffeU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__imm 
                                  + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__rs1_data))
                : ((IData)(4U) + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current))
            : ((IData)(4U) + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result 
        = ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_jalr)
            ? ((IData)(4U) + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current)
            : (((0x37U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg))
                 ? 0U : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__rs1_data) 
               + ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_add)
                   ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__rs2_data
                   : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__imm)));
    vlSelf->pc = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current;
    Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__update_decode_state_TOP(vlSelf->pc, 
                                                                                ((IData)(4U) 
                                                                                + vlSelf->pc), 
                                                                                ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0)
                                                                                 ? 
                                                                                ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_jalr)
                                                                                 ? 
                                                                                (0xfffffffeU 
                                                                                & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__imm 
                                                                                + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__rs1_data))
                                                                                 : 
                                                                                ((IData)(4U) 
                                                                                + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current))
                                                                                 : 
                                                                                ((IData)(4U) 
                                                                                + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current)), vlSelf->inst);
}

void Vysyx_25040109_top___024root___eval_nba(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vysyx_25040109_top___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

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
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
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
                    VL_FATAL_MT("/home/zxj17/ysyx-workbench/npc/vsrc/ysyx_25040109_top.v", 1, "", "Active region did not converge.");
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
                VL_FATAL_MT("/home/zxj17/ysyx-workbench/npc/vsrc/ysyx_25040109_top.v", 1, "", "NBA region did not converge.");
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
