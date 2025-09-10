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
        bufp->chgIData(oldp+0,(vlSelf->ysyx_25040109_top__DOT__ifu_rdata),32);
        bufp->chgIData(oldp+1,(vlSelf->ysyx_25040109_top__DOT__lsu_addr),32);
        bufp->chgIData(oldp+2,(vlSelf->ysyx_25040109_top__DOT__lsu_wdata),32);
        bufp->chgIData(oldp+3,(vlSelf->ysyx_25040109_top__DOT__lsu_rdata),32);
        bufp->chgBit(oldp+4,(vlSelf->ysyx_25040109_top__DOT__lsu_wen));
        bufp->chgCData(oldp+5,(vlSelf->ysyx_25040109_top__DOT__lsu_wmask),4);
        bufp->chgIData(oldp+6,(((IData)(vlSelf->__VdfgTmp_h9113fbb1__0)
                                 ? ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_jalr)
                                     ? (0xfffffffeU 
                                        & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu__DOT__alu_out)
                                     : ((IData)(4U) 
                                        + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current))
                                 : ((IData)(4U) + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current))),32);
        bufp->chgBit(oldp+7,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state));
        bufp->chgBit(oldp+8,((1U & ((~ (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state)) 
                                    | ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state) 
                                       & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load_stall))))));
        bufp->chgIData(oldp+9,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current),32);
        bufp->chgBit(oldp+10,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__current_state));
        bufp->chgIData(oldp+11,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata1_reg),32);
        bufp->chgIData(oldp+12,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata2_reg),32);
        bufp->chgIData(oldp+13,(((0x37U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg))
                                  ? (0xfffff000U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg)
                                  : ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store)
                                      ? (((- (IData)(
                                                     (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | ((0xfe0U 
                                             & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                                >> 0x14U)) 
                                            | (0x1fU 
                                               & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                                  >> 7U))))
                                      : (((- (IData)(
                                                     (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                            >> 0x14U))))),32);
        bufp->chgIData(oldp+14,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result),32);
        bufp->chgIData(oldp+15,((((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load) 
                                  & (2U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__current_state)))
                                  ? ((2U == (7U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                                   >> 0xcU)))
                                      ? vlSelf->ysyx_25040109_top__DOT__lsu_rdata
                                      : ((4U == (7U 
                                                 & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                                    >> 0xcU)))
                                          ? (0xffU 
                                             & vlSelf->ysyx_25040109_top__DOT__lsu_rdata)
                                          : 0U)) : 0U)),32);
        bufp->chgIData(oldp+16,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw)
                                  ? ((0xb00U == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                                 >> 0x14U))
                                      ? (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter)
                                      : ((0xb80U == 
                                          (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                           >> 0x14U))
                                          ? (IData)(
                                                    (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter 
                                                     >> 0x20U))
                                          : ((0xf11U 
                                              == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                                  >> 0x14U))
                                              ? 0x79737978U
                                              : ((0xf12U 
                                                  == 
                                                  (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                                   >> 0x14U))
                                                  ? 0x17e14edU
                                                  : 0U))))
                                  : ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load)
                                      ? (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load) 
                                          & (2U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__current_state)))
                                          ? ((2U == 
                                              (7U & 
                                               (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                                >> 0xcU)))
                                              ? vlSelf->ysyx_25040109_top__DOT__lsu_rdata
                                              : ((4U 
                                                  == 
                                                  (7U 
                                                   & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                                      >> 0xcU)))
                                                  ? 
                                                 (0xffU 
                                                  & vlSelf->ysyx_25040109_top__DOT__lsu_rdata)
                                                  : 0U))
                                          : 0U) : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result))),32);
        bufp->chgBit(oldp+17,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load));
        bufp->chgBit(oldp+18,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store));
        bufp->chgBit(oldp+19,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu__DOT____VdfgTmp_h250803ec__0) 
                               | (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw))));
        bufp->chgBit(oldp+20,((1U & (~ (IData)(vlSelf->__VdfgTmp_h9113fbb1__0)))));
        bufp->chgCData(oldp+21,((0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                          >> 7U))),5);
        bufp->chgCData(oldp+22,((7U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                       >> 0xcU))),3);
        bufp->chgBit(oldp+23,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_add));
        bufp->chgBit(oldp+24,((0x37U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg))));
        bufp->chgBit(oldp+25,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_jalr));
        bufp->chgBit(oldp+26,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw));
        bufp->chgSData(oldp+27,((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                 >> 0x14U)),12);
        bufp->chgIData(oldp+28,(((0xb00U == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                             >> 0x14U))
                                  ? (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter)
                                  : ((0xb80U == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                                 >> 0x14U))
                                      ? (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter 
                                                 >> 0x20U))
                                      : ((0xf11U == 
                                          (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                           >> 0x14U))
                                          ? 0x79737978U
                                          : ((0xf12U 
                                              == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                                  >> 0x14U))
                                              ? 0x17e14edU
                                              : 0U))))),32);
        bufp->chgQData(oldp+29,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter),64);
        bufp->chgBit(oldp+31,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_start));
        bufp->chgBit(oldp+32,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_done));
        bufp->chgBit(oldp+33,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_mem_op));
        bufp->chgBit(oldp+34,((1U & ((~ (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_mem_op)) 
                                     | (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_done)))));
        bufp->chgBit(oldp+35,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state) 
                               & (((~ (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_mem_op)) 
                                   | (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_done)) 
                                  & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__current_state)))));
        bufp->chgBit(oldp+36,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load_stall));
        bufp->chgCData(oldp+37,((0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+38,((0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                          >> 0x14U))),5);
        bufp->chgBit(oldp+39,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state) 
                               & ((~ ((~ (IData)(vlSelf->__VdfgTmp_h9113fbb1__0)) 
                                      | (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load_stall))) 
                                  & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu__DOT____VdfgTmp_h250803ec__0) 
                                     | (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw))))));
        bufp->chgIData(oldp+40,(((0x37U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg))
                                  ? 0U : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata1_reg)),32);
        bufp->chgIData(oldp+41,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_add)
                                  ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata2_reg
                                  : ((0x37U == (0x7fU 
                                                & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg))
                                      ? (0xfffff000U 
                                         & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg)
                                      : ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store)
                                          ? (((- (IData)(
                                                         (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                                          >> 0x1fU))) 
                                              << 0xcU) 
                                             | ((0xfe0U 
                                                 & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                                    >> 0x14U)) 
                                                | (0x1fU 
                                                   & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                                      >> 7U))))
                                          : (((- (IData)(
                                                         (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                                          >> 0x1fU))) 
                                              << 0xcU) 
                                             | (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                                >> 0x14U)))))),32);
        bufp->chgIData(oldp+42,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu__DOT__alu_out),32);
        bufp->chgIData(oldp+43,((0xfffffffeU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu__DOT__alu_out)),32);
        bufp->chgCData(oldp+44,((0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg)),7);
        bufp->chgBit(oldp+45,((IData)((0x13U == (0x707fU 
                                                 & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg)))));
        bufp->chgIData(oldp+46,((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                 >> 0xcU)),20);
        bufp->chgSData(oldp+47,(((0xfe0U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                            >> 0x14U)) 
                                 | (0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                             >> 7U)))),12);
        bufp->chgIData(oldp+48,((0xfffff000U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg)),32);
        bufp->chgIData(oldp+49,((((- (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                              >> 0x1fU))) 
                                  << 0xcU) | (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                              >> 0x14U))),32);
        bufp->chgIData(oldp+50,((((- (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                              >> 0x1fU))) 
                                  << 0xcU) | ((0xfe0U 
                                               & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg 
                                                    >> 7U))))),32);
        bufp->chgIData(oldp+51,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg),32);
        bufp->chgCData(oldp+52,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__current_state),2);
        bufp->chgIData(oldp+53,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[0]),32);
        bufp->chgIData(oldp+54,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[1]),32);
        bufp->chgIData(oldp+55,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[2]),32);
        bufp->chgIData(oldp+56,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[3]),32);
        bufp->chgIData(oldp+57,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[4]),32);
        bufp->chgIData(oldp+58,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[5]),32);
        bufp->chgIData(oldp+59,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[6]),32);
        bufp->chgIData(oldp+60,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[7]),32);
        bufp->chgIData(oldp+61,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[8]),32);
        bufp->chgIData(oldp+62,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[9]),32);
        bufp->chgIData(oldp+63,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[10]),32);
        bufp->chgIData(oldp+64,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[11]),32);
        bufp->chgIData(oldp+65,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[12]),32);
        bufp->chgIData(oldp+66,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[13]),32);
        bufp->chgIData(oldp+67,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[14]),32);
        bufp->chgIData(oldp+68,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[15]),32);
        bufp->chgIData(oldp+69,(vlSelf->ysyx_25040109_top__DOT__mem__DOT__unnamedblk1__DOT__len),32);
    }
    bufp->chgBit(oldp+70,(vlSelf->clk));
    bufp->chgBit(oldp+71,(vlSelf->rst));
    bufp->chgIData(oldp+72,(vlSelf->pc),32);
    bufp->chgIData(oldp+73,(vlSelf->inst),32);
    bufp->chgIData(oldp+74,(vlSelf->p_count_number),32);
    bufp->chgIData(oldp+75,(vlSelf->a0_out),32);
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
