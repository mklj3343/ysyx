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

void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__update_decode_state_TOP(IData/*31:0*/ pc, IData/*31:0*/ snpc, IData/*31:0*/ dnpc, IData/*31:0*/ inst);
void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__itrace_print_TOP(IData/*31:0*/ pc, IData/*31:0*/ instruction_word, IData/*31:0*/ instr_len_bytes, IData/*31:0*/ p_count_number);
void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__printf_finish_TOP();
void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_write_TOP(IData/*31:0*/ addr, IData/*31:0*/ data, IData/*31:0*/ len);
void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__ifu_mem_inst__DOT__verilog_pmem_read_TOP(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ &verilog_pmem_read__Vfuncrtn);

VL_INLINE_OPT void Vysyx_25040109_top___024root___nba_sequent__TOP__0(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vfunc_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_read__7__Vfuncout;
    __Vfunc_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_read__7__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_read__8__Vfuncout;
    __Vfunc_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_read__8__Vfuncout = 0;
    CData/*0:0*/ __Vdly__ysyx_25040109_top__DOT__finish_seen;
    __Vdly__ysyx_25040109_top__DOT__finish_seen = 0;
    CData/*0:0*/ __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__pend;
    __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__pend = 0;
    IData/*31:0*/ __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__addr_q;
    __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__addr_q = 0;
    IData/*31:0*/ __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__wdata_q;
    __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__wdata_q = 0;
    CData/*2:0*/ __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__op_q;
    __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__op_q = 0;
    // Body
    __Vdly__ysyx_25040109_top__DOT__finish_seen = vlSelf->ysyx_25040109_top__DOT__finish_seen;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__ifu_mem_inst__DOT__addr_q 
        = vlSelf->ysyx_25040109_top__DOT__ifu_mem_inst__DOT__addr_q;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__ifu_mem_inst__DOT__pend 
        = vlSelf->ysyx_25040109_top__DOT__ifu_mem_inst__DOT__pend;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__rd_q 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__rd_q;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__op_q 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__op_q;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__busy 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__busy;
    if ((1U & (~ (IData)(vlSelf->rst)))) {
        if (vlSelf->ysyx_25040109_top__DOT__ifu_ready) {
            Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__update_decode_state_TOP(vlSelf->pc, 
                                                                                ((IData)(4U) 
                                                                                + vlSelf->pc), 
                                                                                ((IData)(4U) 
                                                                                + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc), vlSelf->inst);
        }
    }
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid;
    __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__op_q 
        = vlSelf->ysyx_25040109_top__DOT__lsu_mem_inst__DOT__op_q;
    __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__wdata_q 
        = vlSelf->ysyx_25040109_top__DOT__lsu_mem_inst__DOT__wdata_q;
    __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__addr_q 
        = vlSelf->ysyx_25040109_top__DOT__lsu_mem_inst__DOT__addr_q;
    __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__pend 
        = vlSelf->ysyx_25040109_top__DOT__lsu_mem_inst__DOT__pend;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_ready 
        = vlSelf->ysyx_25040109_top__DOT__lsu_ready;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_rdata 
        = vlSelf->ysyx_25040109_top__DOT__lsu_rdata;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__inst_buf 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__inst_buf;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__redirect_pending 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__redirect_pending;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__req_inflight 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__req_inflight;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__have_inst 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__have_inst;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__ifu_mem_valid 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_mem_valid;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__idu_exu_jalr 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_jalr;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_rd_addr 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_rd_addr;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_valid 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_valid;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_mem_op 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_mem_op;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_addr 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_addr;
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_wdata 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_wdata;
    vlSelf->__Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v0 = 0U;
    vlSelf->__Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v16 = 0U;
    vlSelf->__Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v17 = 0U;
    if (vlSelf->rst) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__i = 0x10U;
    }
    if (vlSelf->rst) {
        __Vdly__ysyx_25040109_top__DOT__finish_seen = 0U;
    } else {
        Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__itrace_print_TOP(vlSelf->pc, vlSelf->inst, 4U, vlSelf->p_count_number);
        if (VL_UNLIKELY(((~ (IData)(vlSelf->ysyx_25040109_top__DOT__finish_seen)) 
                         & (0x100073U == vlSelf->ysyx_25040109_top__DOT__inst_top)))) {
            VL_WRITEF("enter finish , a0 decide ending\n");
            Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__printf_finish_TOP();
            __Vdly__ysyx_25040109_top__DOT__finish_seen = 1U;
        }
    }
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid 
        = ((~ (IData)(vlSelf->rst)) & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid) 
                                       & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_idu_ready)));
    if (vlSelf->rst) {
        vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_rdata = 0U;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_ready = 0U;
        __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__pend = 0U;
        __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__addr_q = 0U;
        __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__wdata_q = 0U;
        __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__op_q = 0U;
    } else {
        vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_ready = 0U;
        if (((~ (IData)(vlSelf->ysyx_25040109_top__DOT__lsu_mem_inst__DOT__pend)) 
             & (IData)(vlSelf->ysyx_25040109_top__DOT__lsu_valid))) {
            __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__addr_q 
                = vlSelf->ysyx_25040109_top__DOT__lsu_addr;
            __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__wdata_q 
                = vlSelf->ysyx_25040109_top__DOT__lsu_wdata;
            __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__op_q 
                = vlSelf->ysyx_25040109_top__DOT__lsu_op;
            __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__pend = 1U;
        }
        if (vlSelf->ysyx_25040109_top__DOT__lsu_mem_inst__DOT__pend) {
            if ((4U & (IData)(vlSelf->ysyx_25040109_top__DOT__lsu_mem_inst__DOT__op_q))) {
                if ((1U & (~ ((IData)(vlSelf->ysyx_25040109_top__DOT__lsu_mem_inst__DOT__op_q) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelf->ysyx_25040109_top__DOT__lsu_mem_inst__DOT__op_q)))) {
                        Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_write_TOP(vlSelf->ysyx_25040109_top__DOT__lsu_mem_inst__DOT__addr_q, vlSelf->ysyx_25040109_top__DOT__lsu_mem_inst__DOT__wdata_q, 1U);
                    }
                }
            } else if ((2U & (IData)(vlSelf->ysyx_25040109_top__DOT__lsu_mem_inst__DOT__op_q))) {
                if ((1U & (IData)(vlSelf->ysyx_25040109_top__DOT__lsu_mem_inst__DOT__op_q))) {
                    Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_write_TOP(vlSelf->ysyx_25040109_top__DOT__lsu_mem_inst__DOT__addr_q, vlSelf->ysyx_25040109_top__DOT__lsu_mem_inst__DOT__wdata_q, 4U);
                } else {
                    Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__ifu_mem_inst__DOT__verilog_pmem_read_TOP(vlSelf->ysyx_25040109_top__DOT__lsu_mem_inst__DOT__addr_q, 1U, __Vfunc_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_read__7__Vfuncout);
                    vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_rdata 
                        = __Vfunc_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_read__7__Vfuncout;
                }
            } else if ((1U & (IData)(vlSelf->ysyx_25040109_top__DOT__lsu_mem_inst__DOT__op_q))) {
                Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__ifu_mem_inst__DOT__verilog_pmem_read_TOP(vlSelf->ysyx_25040109_top__DOT__lsu_mem_inst__DOT__addr_q, 4U, __Vfunc_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_read__8__Vfuncout);
                vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_rdata 
                    = __Vfunc_ysyx_25040109_top__DOT__lsu_mem_inst__DOT__verilog_pmem_read__8__Vfuncout;
            }
            vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_ready = 1U;
            __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__pend = 0U;
        }
    }
    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_valid 
        = ((~ (IData)(vlSelf->rst)) & (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid) 
                                        & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready)) 
                                       & (0U != (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op))));
    vlSelf->ysyx_25040109_top__DOT__finish_seen = __Vdly__ysyx_25040109_top__DOT__finish_seen;
    vlSelf->ysyx_25040109_top__DOT__lsu_mem_inst__DOT__pend 
        = __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__pend;
    vlSelf->ysyx_25040109_top__DOT__lsu_mem_inst__DOT__addr_q 
        = __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__addr_q;
    vlSelf->ysyx_25040109_top__DOT__lsu_mem_inst__DOT__wdata_q 
        = __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__wdata_q;
    vlSelf->ysyx_25040109_top__DOT__lsu_mem_inst__DOT__op_q 
        = __Vdly__ysyx_25040109_top__DOT__lsu_mem_inst__DOT__op_q;
    if (vlSelf->rst) {
        vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__idu_exu_jalr = 0U;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_rd_addr = 0U;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_mem_op = 0U;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_addr = 0U;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_wdata = 0U;
        vlSelf->__Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v0 = 1U;
    } else {
        if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid) 
             & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_idu_ready))) {
            vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__idu_exu_jalr 
                = (IData)((0x67U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)));
        }
        if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid) 
             & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready))) {
            vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_rd_addr 
                = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rd_addr;
            vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_mem_op 
                = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op;
            vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_addr 
                = ((1U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op))
                    ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_exu__DOT__alu_res
                    : 0U);
            vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_wdata 
                = ((0U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_addr))
                    ? 0U : ((((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_addr) 
                              == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr)) 
                             & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_write))
                             ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_data
                             : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
                            [(0xfU & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_addr))]));
        }
        if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_write) 
             & (0U != (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_addr)))) {
            vlSelf->__Vdlyvval__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v16 
                = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_data;
            vlSelf->__Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v16 = 1U;
            vlSelf->__Vdlyvdim0__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v16 
                = (0xfU & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_addr));
        }
        if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_write) 
             & (0U != (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr)))) {
            vlSelf->__Vdlyvval__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v17 
                = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_data;
            vlSelf->__Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v17 = 1U;
            vlSelf->__Vdlyvdim0__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v17 
                = (0xfU & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr));
        }
    }
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_write 
        = ((~ (IData)(vlSelf->rst)) & (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid) 
                                        & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready)) 
                                       & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_reg_write) 
                                          & (0U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op)))));
    if (vlSelf->rst) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_addr = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_addr = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_addr = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_data = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rd_addr = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_reg_write = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
    } else {
        if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid) 
             & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready))) {
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_addr 
                = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rd_addr;
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_data 
                = ((1U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op))
                    ? ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_jalr)
                        ? ((IData)(4U) + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_pc)
                        : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_exu__DOT__alu_res)
                    : ((2U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op))
                        ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_exu__DOT__alu_res
                        : 0U));
        }
        if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid) 
             & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_idu_ready))) {
            if ((0x40U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                if ((0x20U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                    if ((0x10U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                    } else if ((8U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                    } else if ((4U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                        if ((2U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                            if ((1U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm 
                                    = (((- (IData)(
                                                   (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                                    >> 0x1fU))) 
                                        << 0xcU) | 
                                       (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                        >> 0x14U));
                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 1U;
                            } else {
                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                            }
                        } else {
                            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                        }
                    } else {
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                    }
                } else {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                }
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_reg_write 
                    = (1U & (IData)((0x27U == (0x3fU 
                                               & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst))));
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op = 0U;
            } else if ((0x20U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                if ((0x10U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                    if ((8U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                    } else if ((4U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                        if ((2U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                            if ((1U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm 
                                    = (0xfffff000U 
                                       & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst);
                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 2U;
                            } else {
                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                            }
                        } else {
                            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                        }
                    } else {
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op 
                            = ((2U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)
                                ? ((1U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)
                                    ? 1U : 0U) : 0U);
                    }
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op = 0U;
                } else if ((8U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                } else if ((4U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                } else if ((2U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                    if ((1U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm 
                            = (((- (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                            >> 0x1fU))) 
                                << 0xcU) | ((0xfe0U 
                                             & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                                >> 0x14U)) 
                                            | (0x1fU 
                                               & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                                  >> 7U))));
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op 
                            = ((2U == (7U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                             >> 0xcU)))
                                ? 3U : ((0U == (7U 
                                                & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                                   >> 0xcU)))
                                         ? 4U : 0U));
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 1U;
                    } else {
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op = 0U;
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                    }
                } else {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                }
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
            } else if ((0x10U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                if ((8U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                } else if ((4U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                } else if ((2U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                    if ((1U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm 
                            = (((- (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                            >> 0x1fU))) 
                                << 0xcU) | (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                            >> 0x14U));
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 1U;
                    } else {
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                    }
                } else {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                }
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_reg_write 
                    = (1U & (IData)((3U == (0xfU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst))));
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op = 0U;
            } else {
                if ((8U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                } else if ((4U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                } else if ((2U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                    if ((1U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst)) {
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm 
                            = (((- (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                            >> 0x1fU))) 
                                << 0xcU) | (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                            >> 0x14U));
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op 
                            = ((2U == (7U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                             >> 0xcU)))
                                ? 1U : ((4U == (7U 
                                                & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                                                   >> 0xcU)))
                                         ? 2U : 0U));
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 1U;
                    } else {
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op = 0U;
                        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                    }
                } else {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op = 0U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op = 0U;
                }
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_reg_write 
                    = (1U & (IData)((3U == (0xfU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst))));
            }
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_addr 
                = (0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                            >> 0xfU));
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_addr 
                = (0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                            >> 0x14U));
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rd_addr 
                = (0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                            >> 7U));
        }
    }
}

void Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__update_cpu_state16_TOP(IData/*31:0*/ pc, IData/*31:0*/ r0, IData/*31:0*/ r1, IData/*31:0*/ r2, IData/*31:0*/ r3, IData/*31:0*/ r4, IData/*31:0*/ r5, IData/*31:0*/ r6, IData/*31:0*/ r7, IData/*31:0*/ r8, IData/*31:0*/ r9, IData/*31:0*/ r10, IData/*31:0*/ r11, IData/*31:0*/ r12, IData/*31:0*/ r13, IData/*31:0*/ r14, IData/*31:0*/ r15);

VL_INLINE_OPT void Vysyx_25040109_top___024root___nba_sequent__TOP__1(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___nba_sequent__TOP__1\n"); );
    // Body
    Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__update_cpu_state16_TOP(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__wb_pc_qq, 
                                                                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
                                                                                [0U], 
                                                                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
                                                                                [1U], 
                                                                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
                                                                                [2U], 
                                                                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
                                                                                [3U], 
                                                                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
                                                                                [4U], 
                                                                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
                                                                                [5U], 
                                                                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
                                                                                [6U], 
                                                                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
                                                                                [7U], 
                                                                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
                                                                                [8U], 
                                                                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
                                                                                [9U], 
                                                                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
                                                                                [0xaU], 
                                                                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
                                                                                [0xbU], 
                                                                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
                                                                                [0xcU], 
                                                                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
                                                                                [0xdU], 
                                                                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
                                                                                [0xeU], 
                                                                                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
                                                                                [0xfU]);
}

VL_INLINE_OPT void Vysyx_25040109_top___024root___nba_sequent__TOP__2(Vysyx_25040109_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root___nba_sequent__TOP__2\n"); );
    // Init
    IData/*31:0*/ __Vfunc_ysyx_25040109_top__DOT__ifu_mem_inst__DOT__verilog_pmem_read__4__Vfuncout;
    __Vfunc_ysyx_25040109_top__DOT__ifu_mem_inst__DOT__verilog_pmem_read__4__Vfuncout = 0;
    // Body
    if (vlSelf->__Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v0) {
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
    if (vlSelf->__Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v16) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[vlSelf->__Vdlyvdim0__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v16] 
            = vlSelf->__Vdlyvval__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v16;
    }
    if (vlSelf->__Vdlyvset__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v17) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[vlSelf->__Vdlyvdim0__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v17] 
            = vlSelf->__Vdlyvval__ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers__v17;
    }
    vlSelf->a0_out = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
        [0xaU];
    if (vlSelf->rst) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__wb_pc_qq = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__wb_pc_q = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_pc = 0U;
        vlSelf->ysyx_25040109_top__DOT__inst_pc_exu_top 
            = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_pc;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc = 0x80000000U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_pc = 0x80000000U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst = 0U;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid = 0U;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__ifu_mem_valid = 0U;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__have_inst = 0U;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__req_inflight = 0U;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__redirect_pending = 0U;
    } else {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__wb_pc_qq 
            = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__wb_pc_q;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__wb_pc_q 
            = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_pc;
        if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid) 
             & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_idu_ready))) {
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_pc 
                = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_pc;
        }
        vlSelf->ysyx_25040109_top__DOT__inst_pc_exu_top 
            = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_pc;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__ifu_mem_valid = 0U;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid = 0U;
        if (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__jump_flag_from_exu) {
            vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__redirect_pending = 1U;
            vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__have_inst = 0U;
        }
        if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__redirect_pending) 
             & (~ (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__req_inflight)))) {
            vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc 
                = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__redirect_addr_q;
            vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__redirect_pending = 0U;
            vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__have_inst = 0U;
        }
        if ((((~ (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__have_inst)) 
              & (~ (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__req_inflight))) 
             & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_ifu_ready))) {
            vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__ifu_mem_valid = 1U;
            vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__req_inflight = 1U;
        }
        if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__req_inflight) 
             & (IData)(vlSelf->ysyx_25040109_top__DOT__ifu_ready))) {
            if (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__redirect_pending) {
                vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc 
                    = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__redirect_addr_q;
                vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__redirect_pending = 0U;
            } else {
                vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__inst_buf 
                    = vlSelf->ysyx_25040109_top__DOT__ifu_data;
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_pc 
                    = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc;
                vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__have_inst = 1U;
                vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc 
                    = ((IData)(4U) + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc);
            }
            vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__req_inflight = 0U;
        }
        if (((((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__have_inst) 
               & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_ifu_ready)) 
              & (~ (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__redirect_pending))) 
             & (~ (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__jump_flag_from_exu)))) {
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst 
                = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__inst_buf;
            vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid = 1U;
            vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__have_inst = 0U;
        }
    }
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__have_inst 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__have_inst;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__req_inflight 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__req_inflight;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__redirect_pending 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__redirect_pending;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__inst_buf 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__inst_buf;
    vlSelf->ysyx_25040109_top__DOT__ifu_idu_pc_top 
        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_pc;
    vlSelf->ysyx_25040109_top__DOT__inst_top = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst;
    if (vlSelf->rst) {
        vlSelf->ysyx_25040109_top__DOT__ifu_data = 0U;
        vlSelf->ysyx_25040109_top__DOT__ifu_ready = 0U;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__ifu_mem_inst__DOT__pend = 0U;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__ifu_mem_inst__DOT__addr_q = 0U;
    } else {
        vlSelf->ysyx_25040109_top__DOT__ifu_ready = 0U;
        if (((~ (IData)(vlSelf->ysyx_25040109_top__DOT__ifu_mem_inst__DOT__pend)) 
             & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_mem_valid))) {
            vlSelf->__Vdly__ysyx_25040109_top__DOT__ifu_mem_inst__DOT__addr_q 
                = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc;
            vlSelf->__Vdly__ysyx_25040109_top__DOT__ifu_mem_inst__DOT__pend = 1U;
        }
        if (VL_UNLIKELY(vlSelf->ysyx_25040109_top__DOT__ifu_mem_inst__DOT__pend)) {
            Vysyx_25040109_top___024root____Vdpiimwrap_ysyx_25040109_top__DOT__ifu_mem_inst__DOT__verilog_pmem_read_TOP(vlSelf->ysyx_25040109_top__DOT__ifu_mem_inst__DOT__addr_q, 4U, __Vfunc_ysyx_25040109_top__DOT__ifu_mem_inst__DOT__verilog_pmem_read__4__Vfuncout);
            vlSelf->ysyx_25040109_top__DOT__ifu_mem_inst__DOT__unnamedblk1__DOT__r_next 
                = __Vfunc_ysyx_25040109_top__DOT__ifu_mem_inst__DOT__verilog_pmem_read__4__Vfuncout;
            vlSelf->ysyx_25040109_top__DOT__ifu_data 
                = vlSelf->ysyx_25040109_top__DOT__ifu_mem_inst__DOT__unnamedblk1__DOT__r_next;
            vlSelf->ysyx_25040109_top__DOT__ifu_ready = 1U;
            vlSelf->__Vdly__ysyx_25040109_top__DOT__ifu_mem_inst__DOT__pend = 0U;
            VL_WRITEF("IFU_MEM READ  addr=0x%08x  rdata=0x%08x\n",
                      32,vlSelf->ysyx_25040109_top__DOT__ifu_mem_inst__DOT__addr_q,
                      32,vlSelf->ysyx_25040109_top__DOT__ifu_mem_inst__DOT__unnamedblk1__DOT__r_next);
        }
    }
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_ifu_ready 
        = (1U & ((IData)(vlSelf->rst) | (~ ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid) 
                                            & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_idu_ready)))));
    vlSelf->pc = vlSelf->ysyx_25040109_top__DOT__ifu_idu_pc_top;
    vlSelf->inst = vlSelf->ysyx_25040109_top__DOT__inst_top;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_mem_valid 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__ifu_mem_valid;
    vlSelf->ysyx_25040109_top__DOT__ifu_mem_inst__DOT__pend 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__ifu_mem_inst__DOT__pend;
    vlSelf->ysyx_25040109_top__DOT__ifu_mem_inst__DOT__addr_q 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__ifu_mem_inst__DOT__addr_q;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_idu_ready 
        = (1U & ((IData)(vlSelf->rst) | (~ ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid) 
                                            & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready)))));
    if (vlSelf->rst) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__redirect_addr_q = 0U;
    } else if (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__jump_flag_from_exu) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__redirect_addr_q 
            = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__jump_addr_from_exu;
    }
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__jump_flag_from_exu 
        = ((~ (IData)(vlSelf->rst)) & (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid) 
                                        & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready)) 
                                       & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_jalr)));
    if (vlSelf->rst) {
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__jump_addr_from_exu = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready = 1U;
        vlSelf->ysyx_25040109_top__DOT__lsu_valid = 0U;
        vlSelf->ysyx_25040109_top__DOT__lsu_addr = 0U;
        vlSelf->ysyx_25040109_top__DOT__lsu_wdata = 0U;
        vlSelf->ysyx_25040109_top__DOT__lsu_op = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_write = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_data = 0U;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__busy = 0U;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__op_q = 0U;
        vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__rd_q = 0U;
    } else {
        if (((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid) 
             & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready))) {
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__jump_addr_from_exu 
                = ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_jalr)
                    ? (0xfffffffeU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_exu__DOT__alu_res)
                    : 0U);
        }
        vlSelf->ysyx_25040109_top__DOT__lsu_valid = 0U;
        vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_write = 0U;
        if (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__busy) {
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready = 0U;
            if (vlSelf->ysyx_25040109_top__DOT__lsu_ready) {
                if ((1U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__op_q))) {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr 
                        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__rd_q;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_data 
                        = vlSelf->ysyx_25040109_top__DOT__lsu_rdata;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_write = 1U;
                } else if ((2U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__op_q))) {
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr 
                        = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__rd_q;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_data 
                        = (0xffU & vlSelf->ysyx_25040109_top__DOT__lsu_rdata);
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_write = 1U;
                }
                vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__busy = 0U;
                vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready = 1U;
            }
        } else {
            vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready = 1U;
            if (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_valid) {
                vlSelf->ysyx_25040109_top__DOT__lsu_addr 
                    = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_addr;
                vlSelf->ysyx_25040109_top__DOT__lsu_wdata 
                    = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_wdata;
                vlSelf->ysyx_25040109_top__DOT__lsu_op 
                    = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_mem_op;
                vlSelf->ysyx_25040109_top__DOT__lsu_valid = 1U;
                vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__op_q 
                    = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_mem_op;
                vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__rd_q 
                    = vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_rd_addr;
                if ((0U != (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_mem_op))) {
                    vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__busy = 1U;
                    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready = 0U;
                }
            }
        }
    }
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_jalr 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__idu_exu_jalr;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid;
    vlSelf->ysyx_25040109_top__DOT__lsu_ready = vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_ready;
    vlSelf->ysyx_25040109_top__DOT__lsu_rdata = vlSelf->__Vdly__ysyx_25040109_top__DOT__lsu_rdata;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_valid 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_valid;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_addr 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_addr;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_wdata 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_wdata;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_mem_op 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_mem_op;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_rd_addr 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_rd_addr;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__busy 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__busy;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__op_q 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__op_q;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__rd_q 
        = vlSelf->__Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_lsu__DOT__rd_q;
    vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_exu__DOT__alu_res 
        = ((1U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op))
            ? (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm 
               + ((0U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_addr))
                   ? 0U : ((((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_addr) 
                             == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr)) 
                            & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_write))
                            ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_data
                            : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
                           [(0xfU & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_addr))])))
            : ((2U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op))
                ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm
                : 0U));
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
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vysyx_25040109_top___024root___nba_sequent__TOP__1(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
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
                    VL_FATAL_MT("/home/zxj17/ysyx-workbench/npc/vsrc/ysyx_25040109_top.v", 2, "", "Active region did not converge.");
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
                VL_FATAL_MT("/home/zxj17/ysyx-workbench/npc/vsrc/ysyx_25040109_top.v", 2, "", "NBA region did not converge.");
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
