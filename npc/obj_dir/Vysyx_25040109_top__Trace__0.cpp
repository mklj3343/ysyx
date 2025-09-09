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
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+0,(vlSelf->ysyx_25040109_top__DOT__mem__DOT__mem_rdata_reg),32);
        bufp->chgIData(oldp+1,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__load_data),32);
        bufp->chgIData(oldp+2,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw)
                                 ? ((0xb00U == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                >> 0x14U))
                                     ? (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter)
                                     : ((0xb80U == 
                                         (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                          >> 0x14U))
                                         ? (IData)(
                                                   (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter 
                                                    >> 0x20U))
                                         : ((0xf11U 
                                             == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                 >> 0x14U))
                                             ? 0x79737978U
                                             : ((0xf12U 
                                                 == 
                                                 (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                  >> 0x14U))
                                                 ? 0x17e14edU
                                                 : 0U))))
                                 : ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load)
                                     ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__load_data
                                     : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result))),32);
        bufp->chgCData(oldp+3,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__raddr1),5);
        bufp->chgCData(oldp+4,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__raddr2),5);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+5,(vlSelf->ysyx_25040109_top__DOT__mem_addr),32);
        bufp->chgIData(oldp+6,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata2_reg),32);
        bufp->chgCData(oldp+7,((7U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                      >> 0xcU))),3);
        bufp->chgIData(oldp+8,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0)
                                 ? ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_jalr)
                                     ? (0xfffffffeU 
                                        & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu__DOT__alu_out)
                                     : ((IData)(4U) 
                                        + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current))
                                 : ((IData)(4U) + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current))),32);
        bufp->chgBit(oldp+9,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state));
        bufp->chgBit(oldp+10,((1U & (~ (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state)))));
        bufp->chgIData(oldp+11,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current),32);
        bufp->chgIData(oldp+12,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg),32);
        bufp->chgIData(oldp+13,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata1_reg),32);
        bufp->chgIData(oldp+14,(((0x37U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg))
                                  ? (0xfffff000U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)
                                  : ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store)
                                      ? (((- (IData)(
                                                     (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | ((0xfe0U 
                                             & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                >> 0x14U)) 
                                            | (0x1fU 
                                               & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                  >> 7U))))
                                      : (((- (IData)(
                                                     (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                            >> 0x14U))))),32);
        bufp->chgIData(oldp+15,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result),32);
        bufp->chgBit(oldp+16,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load));
        bufp->chgBit(oldp+17,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store));
        bufp->chgBit(oldp+18,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu__DOT____VdfgTmp_h250803ec__0) 
                               | (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw))));
        bufp->chgBit(oldp+19,((1U & (~ (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0)))));
        bufp->chgCData(oldp+20,((0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                          >> 7U))),5);
        bufp->chgBit(oldp+21,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_add));
        bufp->chgBit(oldp+22,((0x37U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg))));
        bufp->chgBit(oldp+23,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_jalr));
        bufp->chgBit(oldp+24,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw));
        bufp->chgSData(oldp+25,((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                 >> 0x14U)),12);
        bufp->chgIData(oldp+26,(((0xb00U == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                             >> 0x14U))
                                  ? (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter)
                                  : ((0xb80U == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                 >> 0x14U))
                                      ? (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter 
                                                 >> 0x20U))
                                      : ((0xf11U == 
                                          (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                           >> 0x14U))
                                          ? 0x79737978U
                                          : ((0xf12U 
                                              == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                  >> 0x14U))
                                              ? 0x17e14edU
                                              : 0U))))),32);
        bufp->chgQData(oldp+27,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter),64);
        bufp->chgBit(oldp+29,((1U & ((~ (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state)) 
                                     | ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state) 
                                        & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0) 
                                           & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load)))))));
        bufp->chgBit(oldp+30,((0U != vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current)));
        bufp->chgIData(oldp+31,(((0x37U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg))
                                  ? 0U : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata1_reg)),32);
        bufp->chgIData(oldp+32,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_add)
                                  ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata2_reg
                                  : ((0x37U == (0x7fU 
                                                & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg))
                                      ? (0xfffff000U 
                                         & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)
                                      : ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store)
                                          ? (((- (IData)(
                                                         (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                          >> 0x1fU))) 
                                              << 0xcU) 
                                             | ((0xfe0U 
                                                 & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                    >> 0x14U)) 
                                                | (0x1fU 
                                                   & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                      >> 7U))))
                                          : (((- (IData)(
                                                         (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                          >> 0x1fU))) 
                                              << 0xcU) 
                                             | (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                >> 0x14U)))))),32);
        bufp->chgIData(oldp+33,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu__DOT__alu_out),32);
        bufp->chgIData(oldp+34,((0xfffffffeU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu__DOT__alu_out)),32);
        bufp->chgCData(oldp+35,((0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)),7);
        bufp->chgBit(oldp+36,((IData)((0x13U == (0x707fU 
                                                 & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)))));
        bufp->chgIData(oldp+37,((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                 >> 0xcU)),20);
        bufp->chgSData(oldp+38,(((0xfe0U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                            >> 0x14U)) 
                                 | (0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                             >> 7U)))),12);
        bufp->chgIData(oldp+39,((0xfffff000U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)),32);
        bufp->chgIData(oldp+40,((((- (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                              >> 0x1fU))) 
                                  << 0xcU) | (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                              >> 0x14U))),32);
        bufp->chgIData(oldp+41,((((- (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                              >> 0x1fU))) 
                                  << 0xcU) | ((0xfe0U 
                                               & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                    >> 7U))))),32);
        bufp->chgBit(oldp+42,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state) 
                               & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0) 
                                  & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu__DOT____VdfgTmp_h250803ec__0) 
                                     | (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw))))));
        bufp->chgIData(oldp+43,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[0]),32);
        bufp->chgIData(oldp+44,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[1]),32);
        bufp->chgIData(oldp+45,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[2]),32);
        bufp->chgIData(oldp+46,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[3]),32);
        bufp->chgIData(oldp+47,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[4]),32);
        bufp->chgIData(oldp+48,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[5]),32);
        bufp->chgIData(oldp+49,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[6]),32);
        bufp->chgIData(oldp+50,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[7]),32);
        bufp->chgIData(oldp+51,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[8]),32);
        bufp->chgIData(oldp+52,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[9]),32);
        bufp->chgIData(oldp+53,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[10]),32);
        bufp->chgIData(oldp+54,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[11]),32);
        bufp->chgIData(oldp+55,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[12]),32);
        bufp->chgIData(oldp+56,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[13]),32);
        bufp->chgIData(oldp+57,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[14]),32);
        bufp->chgIData(oldp+58,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[15]),32);
        bufp->chgIData(oldp+59,(vlSelf->ysyx_25040109_top__DOT__mem__DOT__unnamedblk1__DOT__len),32);
    }
    bufp->chgBit(oldp+60,(vlSelf->clk));
    bufp->chgBit(oldp+61,(vlSelf->rst));
    bufp->chgIData(oldp+62,(vlSelf->pc),32);
    bufp->chgIData(oldp+63,(vlSelf->inst),32);
    bufp->chgIData(oldp+64,(vlSelf->p_count_number),32);
    bufp->chgIData(oldp+65,(vlSelf->a0_out),32);
    bufp->chgBit(oldp+66,(((~ (IData)(vlSelf->rst)) 
                           & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state) 
                              & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0) 
                                 & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store))))));
    bufp->chgBit(oldp+67,(((~ (IData)(vlSelf->rst)) 
                           & (((~ (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state)) 
                               | ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state) 
                                  & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0) 
                                     & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load)))) 
                              & (0U != vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current)))));
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
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
