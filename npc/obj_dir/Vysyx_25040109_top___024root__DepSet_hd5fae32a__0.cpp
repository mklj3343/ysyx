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

void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__update_cpu_state__Vdpioc2_TOP(IData/*31:0*/ pc, const VlUnpacked<IData/*31:0*/, 16> &regs);

VL_INLINE_OPT void Vysyx_25040109_top___024root___nba_sequent__TOP__0(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdly__ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr;
    __Vdly__ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v0;
    __Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v0 = 0;
    CData/*3:0*/ __Vdlyvdim0__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v16;
    __Vdlyvdim0__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v16 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v16;
    __Vdlyvval__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v16 = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v16;
    __Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v16 = 0;
    CData/*3:0*/ __Vdlyvdim0__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v17;
    __Vdlyvdim0__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v17 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v17;
    __Vdlyvval__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v17 = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v17;
    __Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v17 = 0;
    // Body
    vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_valid 
        = vlSelf->ysyx_25040109_top__DOT__lsu_valid;
    __Vdly__ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_wdata 
        = vlSelf->ysyx_25040109_top__DOT__lsu_wdata;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_valid 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_valid;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_op 
        = vlSelf->ysyx_25040109_top__DOT__lsu_op;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_addr 
        = vlSelf->ysyx_25040109_top__DOT__lsu_addr;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__idu_exu_pc 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_pc;
    __Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v0 = 0U;
    __Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v16 = 0U;
    __Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v17 = 0U;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_valid 
        = ((~ (IData)(vlSelf->rst)) & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_valid) 
                                       & (IData)(vlSelf->ysyx_25040109_top__DOT__lsu_ready)));
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid 
        = ((~ (IData)(vlSelf->rst)) & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid) 
                                       & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_idu_ready)));
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid 
        = ((~ (IData)(vlSelf->rst)) & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_ifu_ready) 
                                       & (IData)(vlSelf->ysyx_25040109_top__DOT__ifu_ready)));
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_valid 
        = ((~ (IData)(vlSelf->rst)) & (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid) 
                                        & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready)) 
                                       & (0U != (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op))));
    if (vlSelf->rst) {
        __Vdly__ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr = 0U;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_wdata = 0U;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_op = 0U;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_addr = 0U;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__idu_exu_pc = 0U;
    } else {
        if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_valid) 
             & (IData)(vlSelf->ysyx_25040109_top__DOT__lsu_ready))) {
            __Vdly__ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr 
                = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr;
            vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_wdata 
                = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_wdata;
            vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_op 
                = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_mem_op;
            vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_addr 
                = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_addr;
        }
        if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid) 
             & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_idu_ready))) {
            vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__idu_exu_pc 
                = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_pc;
        }
    }
    if (vlSelf->rst) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__i = 0x10U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_data = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_data = 0U;
        __Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v0 = 1U;
    } else {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_data 
            = ((0U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_addr))
                ? 0U : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
               [(0xfU & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_addr))]);
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_data 
            = ((0U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_addr))
                ? 0U : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
               [(0xfU & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_addr))]);
        Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__update_cpu_state__Vdpioc2_TOP(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_pc, vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers);
        if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_write) 
             & (0U != (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_addr)))) {
            __Vdlyvval__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v16 
                = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_data;
            __Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v16 = 1U;
            __Vdlyvdim0__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v16 
                = (0xfU & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_addr));
        }
        if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_write) 
             & (0U != (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr)))) {
            __Vdlyvval__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v17 
                = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_data;
            __Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v17 = 1U;
            __Vdlyvdim0__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v17 
                = (0xfU & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr));
        }
    }
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr 
        = __Vdly__ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr;
    if (__Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v0) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[0U] = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[1U] = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[2U] = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[3U] = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[4U] = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[5U] = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[6U] = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[7U] = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[8U] = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[9U] = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[0xaU] = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[0xbU] = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[0xcU] = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[0xdU] = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[0xeU] = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[0xfU] = 0U;
    }
    if (__Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v16) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[__Vdlyvdim0__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v16] 
            = __Vdlyvval__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v16;
    }
    if (__Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v17) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[__Vdlyvdim0__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v17] 
            = __Vdlyvval__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v17;
    }
    vlSelf->a0_out = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
        [0xaU];
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_write 
        = ((~ (IData)(vlSelf->rst)) & (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_valid) 
                                        & (IData)(vlSelf->ysyx_25040109_top__DOT__lsu_ready)) 
                                       & ((1U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_mem_op)) 
                                          | (2U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_mem_op)))));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_write 
        = ((~ (IData)(vlSelf->rst)) & (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid) 
                                        & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready)) 
                                       & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_reg_write) 
                                          & (0U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op)))));
    if (vlSelf->rst) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_wdata = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_addr = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_addr = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_addr = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_data = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rd_addr = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_mem_op = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_reg_write = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op = 0U;
    } else {
        if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid) 
             & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready))) {
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_wdata 
                = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_data;
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_addr 
                = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rd_addr;
        }
        if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_valid) 
             & (IData)(vlSelf->ysyx_25040109_top__DOT__lsu_ready))) {
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_data 
                = ((1U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_mem_op))
                    ? vlSelf->ysyx_25040109_top__DOT__lsu_rdata
                    : ((2U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_mem_op))
                        ? (0xffU & vlSelf->ysyx_25040109_top__DOT__lsu_rdata)
                        : 0U));
        }
        if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid) 
             & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready))) {
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_mem_op 
                = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op;
        }
        if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid) 
             & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_idu_ready))) {
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_addr 
                = (0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                            >> 0xfU));
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_addr 
                = (0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                            >> 0x14U));
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rd_addr 
                = (0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                            >> 7U));
            if ((0x40U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_reg_write 
                    = (1U & (IData)((0x27U == (0x3fU 
                                               & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst))));
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op = 0U;
            } else if ((0x20U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_reg_write 
                    = (1U & (IData)(((0x10U == (0x18U 
                                                & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) 
                                     & ((4U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)
                                         ? ((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                             >> 1U) 
                                            & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)
                                         : ((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                             >> 1U) 
                                            & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)))));
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op 
                    = ((0x10U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)
                        ? 0U : ((8U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)
                                 ? 0U : ((4U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)
                                          ? 0U : ((2U 
                                                   & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)
                                                   ? 
                                                  ((1U 
                                                    & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)
                                                    ? 
                                                   ((2U 
                                                     == 
                                                     (7U 
                                                      & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                                         >> 0xcU)))
                                                     ? 3U
                                                     : 0U)
                                                    : 0U)
                                                   : 0U))));
            } else if ((0x10U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_reg_write 
                    = (1U & (IData)((3U == (0xfU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst))));
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op = 0U;
            } else {
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_reg_write 
                    = (1U & (IData)((3U == (0xfU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst))));
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op 
                    = ((8U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)
                        ? 0U : ((4U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)
                                 ? 0U : ((2U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)
                                          ? ((1U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)
                                              ? ((0U 
                                                  == 
                                                  (7U 
                                                   & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                                      >> 0xcU)))
                                                  ? 1U
                                                  : 2U)
                                              : 0U)
                                          : 0U)));
            }
        }
    }
}

void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__itrace_print_TOP(IData/*31:0*/ pc, IData/*31:0*/ instruction_word, IData/*31:0*/ instr_len_bytes, IData/*31:0*/ p_count_number);
void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__printf_finish_TOP();

VL_INLINE_OPT void Vysyx_25040109_top___024root___nba_sequent__TOP__1(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___nba_sequent__TOP__1\n"); );
    // Body
    VL_WRITEF("inst:0x%x   ifu_idu_pc_top:0x%08x    \n",
              32,vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst,
              32,vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_pc);
    Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__itrace_print_TOP(vlSelf->pc, vlSelf->inst, 4U, vlSelf->p_count_number);
    if (VL_UNLIKELY((0x100073U == vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst))) {
        VL_WRITEF("enter finishi ,a0 decide ending\n\n");
        Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__printf_finish_TOP();
    }
}

void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__ifu_mem_inst__DOT__verilog_pmem_read_TOP(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ &verilog_pmem_read__Vfuncrtn);
void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__update_decode_state_TOP(IData/*31:0*/ pc, IData/*31:0*/ snpc, IData/*31:0*/ dnpc, IData/*31:0*/ inst);
void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_write_TOP(IData/*31:0*/ addr, IData/*31:0*/ data, IData/*31:0*/ len);

VL_INLINE_OPT void Vysyx_25040109_top___024root___nba_sequent__TOP__2(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___nba_sequent__TOP__2\n"); );
    // Init
    IData/*31:0*/ __Vfunc_ysyx_25040109_top__DOT__ifu_mem_inst__DOT__verilog_pmem_read__4__Vfuncout;
    __Vfunc_ysyx_25040109_top__DOT__ifu_mem_inst__DOT__verilog_pmem_read__4__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_read__6__Vfuncout;
    __Vfunc_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_read__6__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_read__7__Vfuncout;
    __Vfunc_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_read__7__Vfuncout = 0;
    // Body
    if (vlSelf->rst) {
        vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc = 0x80000000U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_pc = 0x80000000U;
    } else if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_ifu_ready) 
                & (IData)(vlSelf->ysyx_25040109_top__DOT__ifu_ready))) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_pc 
            = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc 
            = ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__jump_flag_from_exu)
                ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__jump_addr_from_exu
                : ((IData)(4U) + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc));
    }
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__jump_flag_from_exu 
        = ((~ (IData)(vlSelf->rst)) & (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid) 
                                        & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready)) 
                                       & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_jalr)));
    if (vlSelf->rst) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_addr = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_data = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__jump_addr_from_exu = 0U;
    } else if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid) 
                & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready))) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__jump_addr_from_exu 
            = ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_jalr)
                ? (0xfffffffeU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_exu__DOT__alu_result)
                : 0U);
        if ((1U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op))) {
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_addr 
                = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_exu__DOT__alu_result;
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_data 
                = ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_jalr)
                    ? ((IData)(4U) + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_pc)
                    : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_exu__DOT__alu_result);
        } else {
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_data 
                = ((2U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op))
                    ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm
                    : 0U);
        }
    }
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_pc 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__idu_exu_pc;
    vlSelf->pc = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_pc;
    if ((1U & (~ (IData)(vlSelf->rst)))) {
        if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid) 
             & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready))) {
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_exu__DOT__alu_result 
                = ((1U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op))
                    ? (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_data 
                       + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm)
                    : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm);
        }
    }
    if (vlSelf->rst) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_jalr = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst = 0U;
    } else {
        if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid) 
             & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_idu_ready))) {
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_jalr 
                = (IData)((0x67U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)));
            if ((0x40U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                if ((0x20U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                    if ((0x10U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                    } else if ((8U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                    } else if ((4U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                        if ((2U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                            if ((1U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 1U;
                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm 
                                    = (((- (IData)(
                                                   (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                                    >> 0x1fU))) 
                                        << 0xcU) | 
                                       (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                        >> 0x14U));
                            } else {
                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                            }
                        } else {
                            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                        }
                    } else {
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                    }
                } else {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                }
            } else if ((0x20U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                if ((0x10U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                    if ((8U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                    } else if ((4U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                        if ((2U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                            if ((1U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 2U;
                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm 
                                    = (0xfffff000U 
                                       & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst);
                            } else {
                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                            }
                        } else {
                            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                        }
                    } else {
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op 
                            = ((2U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)
                                ? ((1U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)
                                    ? 1U : 0U) : 0U);
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                    }
                } else if ((8U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                } else if ((4U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                } else if ((2U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                    if ((1U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 1U;
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm 
                            = (((- (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                            >> 0x1fU))) 
                                << 0xcU) | ((0xfe0U 
                                             & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                                >> 0x14U)) 
                                            | (0x1fU 
                                               & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                                  >> 7U))));
                    } else {
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                    }
                } else {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                }
            } else if ((0x10U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                if ((8U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                } else if ((4U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                } else if ((2U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                    if ((1U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 1U;
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm 
                            = (((- (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                            >> 0x1fU))) 
                                << 0xcU) | (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                            >> 0x14U));
                    } else {
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                    }
                } else {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                }
            } else if ((8U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
            } else if ((4U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
            } else if ((2U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                if ((1U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 1U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm 
                        = (((- (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                        >> 0x1fU))) 
                            << 0xcU) | (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                        >> 0x14U));
                } else {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                }
            } else {
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
            }
        }
        if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_ifu_ready) 
             & (IData)(vlSelf->ysyx_25040109_top__DOT__ifu_ready))) {
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                = vlSelf->ysyx_25040109_top__DOT__ifu_data;
        }
    }
    vlSelf->inst = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst;
    if (vlSelf->rst) {
        vlSelf->ysyx_25040109_top__DOT__ifu_data = 0U;
        vlSelf->ysyx_25040109_top__DOT__ifu_ready = 1U;
    } else if (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid) {
        Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__ifu_mem_inst__DOT__verilog_pmem_read_TOP(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc, 4U, __Vfunc_ysyx_25040109_top__DOT__ifu_mem_inst__DOT__verilog_pmem_read__4__Vfuncout);
        vlSelf->ysyx_25040109_top__DOT__ifu_ready = 0U;
        vlSelf->ysyx_25040109_top__DOT__ifu_data = __Vfunc_ysyx_25040109_top__DOT__ifu_mem_inst__DOT__verilog_pmem_read__4__Vfuncout;
        vlSelf->ysyx_25040109_top__DOT__ifu_ready = 1U;
    } else {
        vlSelf->ysyx_25040109_top__DOT__ifu_ready = 1U;
    }
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_ifu_ready 
        = (1U & ((IData)(vlSelf->rst) | (~ ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid) 
                                            & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_idu_ready)))));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid;
    Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__update_decode_state_TOP(vlSelf->pc, 
                                                                                ((IData)(4U) 
                                                                                + vlSelf->pc), 
                                                                                ((IData)(4U) 
                                                                                + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc), vlSelf->inst);
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_idu_ready 
        = (1U & ((IData)(vlSelf->rst) | (~ ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid) 
                                            & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready)))));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready 
        = (1U & ((IData)(vlSelf->rst) | (~ ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_valid) 
                                            & (IData)(vlSelf->ysyx_25040109_top__DOT__lsu_ready)))));
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_valid 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_valid;
    if (vlSelf->rst) {
        vlSelf->ysyx_25040109_top__DOT__lsu_rdata = 0U;
        vlSelf->ysyx_25040109_top__DOT__lsu_ready = 1U;
    } else if (vlSelf->ysyx_25040109_top__DOT__lsu_valid) {
        vlSelf->ysyx_25040109_top__DOT__lsu_ready = 0U;
        if ((2U & (IData)(vlSelf->ysyx_25040109_top__DOT__lsu_op))) {
            if ((1U & (IData)(vlSelf->ysyx_25040109_top__DOT__lsu_op))) {
                Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_write_TOP(vlSelf->ysyx_25040109_top__DOT__lsu_addr, vlSelf->ysyx_25040109_top__DOT__lsu_wdata, 4U);
            } else {
                Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__ifu_mem_inst__DOT__verilog_pmem_read_TOP(vlSelf->ysyx_25040109_top__DOT__lsu_addr, 1U, __Vfunc_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_read__6__Vfuncout);
                vlSelf->ysyx_25040109_top__DOT__lsu_rdata 
                    = __Vfunc_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_read__6__Vfuncout;
            }
        } else if ((1U & (IData)(vlSelf->ysyx_25040109_top__DOT__lsu_op))) {
            Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__ifu_mem_inst__DOT__verilog_pmem_read_TOP(vlSelf->ysyx_25040109_top__DOT__lsu_addr, 4U, __Vfunc_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_read__7__Vfuncout);
            vlSelf->ysyx_25040109_top__DOT__lsu_rdata 
                = __Vfunc_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_read__7__Vfuncout;
        } else {
            Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_write_TOP(vlSelf->ysyx_25040109_top__DOT__lsu_addr, vlSelf->ysyx_25040109_top__DOT__lsu_wdata, 1U);
        }
        vlSelf->ysyx_25040109_top__DOT__lsu_ready = 1U;
    } else {
        vlSelf->ysyx_25040109_top__DOT__lsu_ready = 1U;
    }
    vlSelf->ysyx_25040109_top__DOT__lsu_valid = vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_valid;
    vlSelf->ysyx_25040109_top__DOT__lsu_op = vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_op;
    vlSelf->ysyx_25040109_top__DOT__lsu_addr = vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_addr;
    vlSelf->ysyx_25040109_top__DOT__lsu_wdata = vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_wdata;
}

void Vysyx_25040109_top___024root___eval_nba(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vysyx_25040109_top___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vysyx_25040109_top___024root___nba_sequent__TOP__1(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vysyx_25040109_top___024root___nba_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
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
    VlTriggerVec<2> __VpreTriggered;
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
                    VL_FATAL_MT("/home/zxj17/ysyx-workbench/npc/vsrc/ysyx_25040109_top.v", 3, "", "Active region did not converge.");
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
                VL_FATAL_MT("/home/zxj17/ysyx-workbench/npc/vsrc/ysyx_25040109_top.v", 3, "", "NBA region did not converge.");
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
