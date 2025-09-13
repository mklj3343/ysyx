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
        bufp->chgCData(oldp+7,(vlSelf->ysyx_25040109_top__DOT__lsu_rlen),3);
        bufp->chgIData(oldp+8,(vlSelf->ysyx_25040109_top__DOT__lsu_wdata),32);
        bufp->chgCData(oldp+9,(vlSelf->ysyx_25040109_top__DOT__lsu_wmask),4);
        bufp->chgBit(oldp+10,(vlSelf->ysyx_25040109_top__DOT__lsu_respValid));
        bufp->chgIData(oldp+11,(vlSelf->ysyx_25040109_top__DOT__lsu_rdata),32);
        bufp->chgIData(oldp+12,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0)
                                  ? ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_jalr)
                                      ? (0xfffffffeU 
                                         & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__imm 
                                            + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata1_reg))
                                      : ((IData)(4U) 
                                         + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current))
                                  : ((IData)(4U) + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current))),32);
        bufp->chgCData(oldp+13,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__state),4);
        bufp->chgIData(oldp+14,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg),32);
        bufp->chgIData(oldp+15,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__load_data),32);
        bufp->chgBit(oldp+16,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__fetch_en));
        bufp->chgBit(oldp+17,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_en));
        bufp->chgBit(oldp+18,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__prev_is_load));
        bufp->chgCData(oldp+19,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__prev_rd_addr),5);
        bufp->chgIData(oldp+20,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current),32);
        bufp->chgIData(oldp+21,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata1_reg),32);
        bufp->chgIData(oldp+22,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata2_reg),32);
        bufp->chgIData(oldp+23,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__imm),32);
        bufp->chgIData(oldp+24,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result),32);
        bufp->chgIData(oldp+25,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw)
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
        bufp->chgBit(oldp+26,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load));
        bufp->chgBit(oldp+27,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store));
        bufp->chgBit(oldp+28,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__reg_write_en));
        bufp->chgBit(oldp+29,((1U & (~ (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0)))));
        bufp->chgCData(oldp+30,((0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                          >> 7U))),5);
        bufp->chgCData(oldp+31,((7U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                       >> 0xcU))),3);
        bufp->chgBit(oldp+32,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_add));
        bufp->chgBit(oldp+33,((0x37U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg))));
        bufp->chgBit(oldp+34,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_jalr));
        bufp->chgBit(oldp+35,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw));
        bufp->chgBit(oldp+36,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_addi));
        bufp->chgSData(oldp+37,((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                 >> 0x14U)),12);
        bufp->chgIData(oldp+38,(((0xb00U == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                             >> 0x14U))
                                  ? (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter)
                                  : ((0xb80U == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                 >> 0x14U))
                                      ? (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter 
                                                 >> 0x20U))
                                      : 0U))),32);
        bufp->chgQData(oldp+39,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter),64);
        bufp->chgBit(oldp+41,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__fetch_done));
        bufp->chgIData(oldp+42,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__inst_reg),32);
        bufp->chgBit(oldp+43,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_done));
        bufp->chgIData(oldp+44,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg),32);
        bufp->chgCData(oldp+45,((0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+46,((0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                          >> 0x14U))),5);
        bufp->chgBit(oldp+47,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__prev_is_load) 
                               & ((0U != (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__prev_rd_addr)) 
                                  & ((0x37U != (0x7fU 
                                                & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)) 
                                     & (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__prev_rd_addr) 
                                         == (0x1fU 
                                             & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                >> 0xfU))) 
                                        | ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__prev_rd_addr) 
                                           == (0x1fU 
                                               & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                  >> 0x14U)))))))));
        bufp->chgCData(oldp+48,((0xffU & ((0U == (3U 
                                                  & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result))
                                           ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg
                                           : ((1U == 
                                               (3U 
                                                & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result))
                                               ? (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg 
                                                  >> 8U)
                                               : ((2U 
                                                   == 
                                                   (3U 
                                                    & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result))
                                                   ? 
                                                  (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg 
                                                   >> 0x10U)
                                                   : 
                                                  (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__rdata_reg 
                                                   >> 0x18U)))))),8);
        bufp->chgBit(oldp+49,((((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hd745c079__0) 
                                & (3U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__state))) 
                               | ((4U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__state)) 
                                  & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_done)))));
        bufp->chgBit(oldp+50,((((3U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__state)) 
                                & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__reg_write_en) 
                                   & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hd745c079__0) 
                                      & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0)))) 
                               | ((5U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__state)) 
                                  & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0) 
                                     & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__reg_write_en))))));
        bufp->chgIData(oldp+51,(((0x37U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg))
                                  ? 0U : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata1_reg)),32);
        bufp->chgIData(oldp+52,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_add)
                                  ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata2_reg
                                  : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__imm)),32);
        bufp->chgIData(oldp+53,((((0x37U == (0x7fU 
                                             & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg))
                                   ? 0U : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata1_reg) 
                                 + ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_add)
                                     ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata2_reg
                                     : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__imm))),32);
        bufp->chgIData(oldp+54,((0xfffffffeU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__imm 
                                                + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata1_reg))),32);
        bufp->chgCData(oldp+55,((0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)),7);
        bufp->chgIData(oldp+56,((0xfffff000U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)),32);
        bufp->chgIData(oldp+57,((((- (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                              >> 0x1fU))) 
                                  << 0xcU) | (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                              >> 0x14U))),32);
        bufp->chgIData(oldp+58,((((- (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                              >> 0x1fU))) 
                                  << 0xcU) | ((0xfe0U 
                                               & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                    >> 7U))))),32);
        bufp->chgBit(oldp+59,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu__DOT__state));
        bufp->chgBit(oldp+60,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu__DOT__state));
        bufp->chgCData(oldp+61,((3U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result)),2);
        bufp->chgCData(oldp+62,((0xfU & ((0U == (7U 
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
        bufp->chgIData(oldp+63,(((0U == (7U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                               >> 0xcU)))
                                  ? ((0x1fU >= (0x18U 
                                                & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result 
                                                   << 3U)))
                                      ? ((0xffU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata2_reg) 
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
                                                   ((0xffffU 
                                                     & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata2_reg) 
                                                    << 
                                                    (0x10U 
                                                     & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result 
                                                        << 3U)))
                                                    : 0U)
                                                : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata2_reg))),32);
        bufp->chgIData(oldp+64,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[0]),32);
        bufp->chgIData(oldp+65,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[1]),32);
        bufp->chgIData(oldp+66,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[2]),32);
        bufp->chgIData(oldp+67,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[3]),32);
        bufp->chgIData(oldp+68,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[4]),32);
        bufp->chgIData(oldp+69,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[5]),32);
        bufp->chgIData(oldp+70,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[6]),32);
        bufp->chgIData(oldp+71,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[7]),32);
        bufp->chgIData(oldp+72,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[8]),32);
        bufp->chgIData(oldp+73,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[9]),32);
        bufp->chgIData(oldp+74,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[10]),32);
        bufp->chgIData(oldp+75,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[11]),32);
        bufp->chgIData(oldp+76,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[12]),32);
        bufp->chgIData(oldp+77,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[13]),32);
        bufp->chgIData(oldp+78,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[14]),32);
        bufp->chgIData(oldp+79,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[15]),32);
        bufp->chgCData(oldp+80,(vlSelf->ysyx_25040109_top__DOT__mem__DOT__write_len),3);
    }
    bufp->chgBit(oldp+81,(vlSelf->clk));
    bufp->chgBit(oldp+82,(vlSelf->rst));
    bufp->chgIData(oldp+83,(vlSelf->pc),32);
    bufp->chgIData(oldp+84,(vlSelf->inst),32);
    bufp->chgIData(oldp+85,(vlSelf->p_count_number),32);
    bufp->chgIData(oldp+86,(vlSelf->a0_out),32);
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
