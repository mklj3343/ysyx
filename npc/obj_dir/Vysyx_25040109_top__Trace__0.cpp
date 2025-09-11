// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vysyx_25040109_top__Syms.h"


void Vysyx_25040109_top___024root__trace_chg_sub_0(Vysyx_25040109_top___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vysyx_25040109_top___024root__trace_chg_top_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root__trace_chg_top_0\n"); );
    // Init
    Vysyx_25040109_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_25040109_top___024root*>(voidSelf);
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vysyx_25040109_top___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vysyx_25040109_top___024root__trace_chg_sub_0(Vysyx_25040109_top___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->ysyx_25040109_top__DOT__ifu_reqValid));
        bufp->chgIData(oldp+1,(vlSelf->ysyx_25040109_top__DOT__ifu_addr),32);
        bufp->chgBit(oldp+2,(vlSelf->ysyx_25040109_top__DOT__ifu_respValid));
        bufp->chgIData(oldp+3,(vlSelf->ysyx_25040109_top__DOT__ifu_rdata),32);
        bufp->chgBit(oldp+4,(vlSelf->ysyx_25040109_top__DOT__lsu_reqValid));
        bufp->chgIData(oldp+5,(vlSelf->ysyx_25040109_top__DOT__lsu_addr),32);
        bufp->chgBit(oldp+6,(vlSelf->ysyx_25040109_top__DOT__lsu_wen));
        bufp->chgIData(oldp+7,(vlSelf->ysyx_25040109_top__DOT__lsu_wdata),32);
        bufp->chgCData(oldp+8,(vlSelf->ysyx_25040109_top__DOT__lsu_wmask),4);
        bufp->chgBit(oldp+9,(vlSelf->ysyx_25040109_top__DOT__lsu_respValid));
        bufp->chgIData(oldp+10,(vlSelf->ysyx_25040109_top__DOT__lsu_rdata),32);
        bufp->chgIData(oldp+11,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0)
                                  ? ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_jalr)
                                      ? (0xfffffffeU 
                                         & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__imm 
                                            + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__rs1_data))
                                      : ((IData)(4U) 
                                         + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current))
                                  : ((IData)(4U) + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current))),32);
        bufp->chgCData(oldp+12,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__state),2);
        bufp->chgIData(oldp+13,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg),32);
        bufp->chgIData(oldp+14,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__load_data),32);
        bufp->chgBit(oldp+15,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__fetch_en));
        bufp->chgBit(oldp+16,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_en));
        bufp->chgIData(oldp+17,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current),32);
        bufp->chgIData(oldp+18,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__rs1_data),32);
        bufp->chgIData(oldp+19,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__rs2_data),32);
        bufp->chgIData(oldp+20,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__imm),32);
        bufp->chgIData(oldp+21,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result),32);
        bufp->chgIData(oldp+22,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw)
                                  ? ((0xb00U == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                 >> 0x14U))
                                      ? (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter)
                                      : ((0xb80U == 
                                          (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                           >> 0x14U))
                                          ? (IData)(
                                                    (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter 
                                                     >> 0x20U))
                                          : 0U)) : 
                                 ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load)
                                   ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__load_data
                                   : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result))),32);
        bufp->chgBit(oldp+23,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load));
        bufp->chgBit(oldp+24,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store));
        bufp->chgBit(oldp+25,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__reg_write_en));
        bufp->chgBit(oldp+26,((1U & (~ (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0)))));
        bufp->chgCData(oldp+27,((0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                          >> 7U))),5);
        bufp->chgCData(oldp+28,((7U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                       >> 0xcU))),3);
        bufp->chgBit(oldp+29,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_add));
        bufp->chgBit(oldp+30,((0x37U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg))));
        bufp->chgBit(oldp+31,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_jalr));
        bufp->chgBit(oldp+32,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw));
        bufp->chgSData(oldp+33,((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                 >> 0x14U)),12);
        bufp->chgIData(oldp+34,(((0xb00U == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                             >> 0x14U))
                                  ? (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter)
                                  : ((0xb80U == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                 >> 0x14U))
                                      ? (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter 
                                                 >> 0x20U))
                                      : 0U))),32);
        bufp->chgQData(oldp+35,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter),64);
        bufp->chgBit(oldp+37,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__state) 
                               & (IData)(vlSelf->ysyx_25040109_top__DOT__ifu_respValid))));
        bufp->chgIData(oldp+38,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg),32);
        bufp->chgBit(oldp+39,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_done));
        bufp->chgIData(oldp+40,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg),32);
        bufp->chgCData(oldp+41,((0xffU & ((2U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result)
                                           ? ((1U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result)
                                               ? (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg 
                                                  >> 0x18U)
                                               : (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg 
                                                  >> 0x10U))
                                           : ((1U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result)
                                               ? (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg 
                                                  >> 8U)
                                               : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg)))),8);
        bufp->chgBit(oldp+42,((((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hd745c079__0) 
                                & (2U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__state))) 
                               | (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_h21df59c1__0))));
        bufp->chgBit(oldp+43,((((2U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__state)) 
                                & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__reg_write_en) 
                                   & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hd745c079__0) 
                                      & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0)))) 
                               | ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_h21df59c1__0) 
                                  & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0) 
                                     & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__reg_write_en))))));
        bufp->chgIData(oldp+44,(((0x37U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg))
                                  ? 0U : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__rs1_data)),32);
        bufp->chgIData(oldp+45,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_add)
                                  ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__rs2_data
                                  : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__imm)),32);
        bufp->chgIData(oldp+46,((((0x37U == (0x7fU 
                                             & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg))
                                   ? 0U : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__rs1_data) 
                                 + ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_add)
                                     ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__rs2_data
                                     : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__imm))),32);
        bufp->chgIData(oldp+47,((0xfffffffeU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__imm 
                                                + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__rs1_data))),32);
        bufp->chgCData(oldp+48,((0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)),7);
        bufp->chgBit(oldp+49,((IData)((0x13U == (0x707fU 
                                                 & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)))));
        bufp->chgIData(oldp+50,((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                 >> 0xcU)),20);
        bufp->chgSData(oldp+51,(((0xfe0U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                            >> 0x14U)) 
                                 | (0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                             >> 7U)))),12);
        bufp->chgIData(oldp+52,((0xfffff000U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)),32);
        bufp->chgIData(oldp+53,((((- (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                              >> 0x1fU))) 
                                  << 0xcU) | (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                              >> 0x14U))),32);
        bufp->chgIData(oldp+54,((((- (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                              >> 0x1fU))) 
                                  << 0xcU) | ((0xfe0U 
                                               & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                    >> 7U))))),32);
        bufp->chgBit(oldp+55,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__state));
        bufp->chgBit(oldp+56,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__state));
        bufp->chgCData(oldp+57,((3U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result)),2);
        bufp->chgCData(oldp+58,((0xfU & ((0U == (7U 
                                                 & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                    >> 0xcU)))
                                          ? ((IData)(1U) 
                                             << (3U 
                                                 & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result))
                                          : ((1U == 
                                              (7U & 
                                               (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                >> 0xcU)))
                                              ? ((3U 
                                                  >= 
                                                  (2U 
                                                   & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result))
                                                  ? 
                                                 ((IData)(3U) 
                                                  << 
                                                  (2U 
                                                   & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result))
                                                  : 0U)
                                              : 0xfU)))),4);
        bufp->chgIData(oldp+59,(((0U == (7U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                               >> 0xcU)))
                                  ? ((0x1fU >= (0x18U 
                                                & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result 
                                                   << 3U)))
                                      ? (((0U == (0x1fU 
                                                  & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                     >> 0x14U)))
                                           ? 0U : (0xffU 
                                                   & vlSelf->__VdfgTmp_he3bf7288__0)) 
                                         << (0x18U 
                                             & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result 
                                                << 3U)))
                                      : 0U) : ((1U 
                                                == 
                                                (7U 
                                                 & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                    >> 0xcU)))
                                                ? (
                                                   (0x1fU 
                                                    >= 
                                                    (0x10U 
                                                     & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result 
                                                        << 3U)))
                                                    ? 
                                                   (((0U 
                                                      == 
                                                      (0x1fU 
                                                       & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                          >> 0x14U)))
                                                      ? 0U
                                                      : 
                                                     (0xffffU 
                                                      & vlSelf->__VdfgTmp_he3bf7288__0)) 
                                                    << 
                                                    (0x10U 
                                                     & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result 
                                                        << 3U)))
                                                    : 0U)
                                                : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__rs2_data))),32);
        bufp->chgCData(oldp+60,((0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+61,((0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                          >> 0x14U))),5);
        bufp->chgIData(oldp+62,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[0]),32);
        bufp->chgIData(oldp+63,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[1]),32);
        bufp->chgIData(oldp+64,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[2]),32);
        bufp->chgIData(oldp+65,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[3]),32);
        bufp->chgIData(oldp+66,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[4]),32);
        bufp->chgIData(oldp+67,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[5]),32);
        bufp->chgIData(oldp+68,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[6]),32);
        bufp->chgIData(oldp+69,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[7]),32);
        bufp->chgIData(oldp+70,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[8]),32);
        bufp->chgIData(oldp+71,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[9]),32);
        bufp->chgIData(oldp+72,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[10]),32);
        bufp->chgIData(oldp+73,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[11]),32);
        bufp->chgIData(oldp+74,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[12]),32);
        bufp->chgIData(oldp+75,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[13]),32);
        bufp->chgIData(oldp+76,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[14]),32);
        bufp->chgIData(oldp+77,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[15]),32);
    }
    bufp->chgBit(oldp+78,(vlSelf->clk));
    bufp->chgBit(oldp+79,(vlSelf->rst));
    bufp->chgIData(oldp+80,(vlSelf->pc),32);
    bufp->chgIData(oldp+81,(vlSelf->inst),32);
    bufp->chgIData(oldp+82,(vlSelf->p_count_number),32);
    bufp->chgIData(oldp+83,(vlSelf->a0_out),32);
}

void Vysyx_25040109_top___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root__trace_cleanup\n"); );
    // Init
    Vysyx_25040109_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_25040109_top___024root*>(voidSelf);
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
