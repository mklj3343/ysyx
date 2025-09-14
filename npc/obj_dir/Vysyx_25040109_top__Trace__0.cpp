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
        bufp->chgCData(oldp+0,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rd_addr),5);
        bufp->chgCData(oldp+1,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op),2);
        bufp->chgBit(oldp+2,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_reg_write));
        bufp->chgIData(oldp+3,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_wdata),32);
        bufp->chgCData(oldp+4,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_mem_op),2);
        bufp->chgCData(oldp+5,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_addr),5);
        bufp->chgBit(oldp+6,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_write));
        bufp->chgCData(oldp+7,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr),5);
        bufp->chgIData(oldp+8,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_data),32);
        bufp->chgBit(oldp+9,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_write));
        bufp->chgIData(oldp+10,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+11,(vlSelf->ysyx_25040109_top__DOT__ifu_data),32);
        bufp->chgBit(oldp+12,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid));
        bufp->chgBit(oldp+13,(vlSelf->ysyx_25040109_top__DOT__ifu_ready));
        bufp->chgIData(oldp+14,(vlSelf->ysyx_25040109_top__DOT__lsu_addr),32);
        bufp->chgIData(oldp+15,(vlSelf->ysyx_25040109_top__DOT__lsu_wdata),32);
        bufp->chgIData(oldp+16,(vlSelf->ysyx_25040109_top__DOT__lsu_rdata),32);
        bufp->chgCData(oldp+17,(vlSelf->ysyx_25040109_top__DOT__lsu_op),2);
        bufp->chgBit(oldp+18,(vlSelf->ysyx_25040109_top__DOT__lsu_valid));
        bufp->chgBit(oldp+19,(vlSelf->ysyx_25040109_top__DOT__lsu_ready));
        bufp->chgIData(oldp+20,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst),32);
        bufp->chgIData(oldp+21,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_pc),32);
        bufp->chgIData(oldp+22,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_pc),32);
        bufp->chgIData(oldp+23,(((IData)(4U) + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc)),32);
        bufp->chgBit(oldp+24,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_ifu_ready));
        bufp->chgIData(oldp+25,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_data),32);
        bufp->chgIData(oldp+26,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_data),32);
        bufp->chgCData(oldp+27,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_addr),5);
        bufp->chgCData(oldp+28,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_addr),5);
        bufp->chgIData(oldp+29,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm),32);
        bufp->chgCData(oldp+30,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op),4);
        bufp->chgBit(oldp+31,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_jalr));
        bufp->chgBit(oldp+32,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid));
        bufp->chgBit(oldp+33,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_idu_ready));
        bufp->chgIData(oldp+34,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_addr),32);
        bufp->chgBit(oldp+35,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_valid));
        bufp->chgBit(oldp+36,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready));
        bufp->chgIData(oldp+37,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_data),32);
        bufp->chgBit(oldp+38,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__jump_flag_from_exu));
        bufp->chgIData(oldp+39,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__jump_addr_from_exu),32);
        bufp->chgIData(oldp+40,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_exu__DOT__alu_result),32);
        bufp->chgIData(oldp+41,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc),32);
        bufp->chgIData(oldp+42,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[0]),32);
        bufp->chgIData(oldp+43,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[1]),32);
        bufp->chgIData(oldp+44,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[2]),32);
        bufp->chgIData(oldp+45,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[3]),32);
        bufp->chgIData(oldp+46,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[4]),32);
        bufp->chgIData(oldp+47,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[5]),32);
        bufp->chgIData(oldp+48,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[6]),32);
        bufp->chgIData(oldp+49,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[7]),32);
        bufp->chgIData(oldp+50,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[8]),32);
        bufp->chgIData(oldp+51,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[9]),32);
        bufp->chgIData(oldp+52,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[10]),32);
        bufp->chgIData(oldp+53,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[11]),32);
        bufp->chgIData(oldp+54,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[12]),32);
        bufp->chgIData(oldp+55,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[13]),32);
        bufp->chgIData(oldp+56,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[14]),32);
        bufp->chgIData(oldp+57,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[15]),32);
    }
    bufp->chgBit(oldp+58,(vlSelf->clk));
    bufp->chgBit(oldp+59,(vlSelf->rst));
    bufp->chgIData(oldp+60,(vlSelf->pc),32);
    bufp->chgIData(oldp+61,(vlSelf->inst),32);
    bufp->chgIData(oldp+62,(vlSelf->p_count_number),32);
    bufp->chgIData(oldp+63,(vlSelf->a0_out),32);
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
