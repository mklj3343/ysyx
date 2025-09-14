// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vysyx_25040109_top.h for the primary calling header

#ifndef VERILATED_VYSYX_25040109_TOP___024ROOT_H_
#define VERILATED_VYSYX_25040109_TOP___024ROOT_H_  // guard

#include "verilated.h"

class Vysyx_25040109_top__Syms;

class Vysyx_25040109_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ ysyx_25040109_top__DOT__ifu_ready;
    CData/*1:0*/ ysyx_25040109_top__DOT__lsu_op;
    CData/*0:0*/ ysyx_25040109_top__DOT__lsu_valid;
    CData/*0:0*/ ysyx_25040109_top__DOT__lsu_ready;
    CData/*0:0*/ ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid;
    CData/*0:0*/ ysyx_25040109_top__DOT__cpu__DOT__idu_ifu_ready;
    CData/*4:0*/ ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_addr;
    CData/*4:0*/ ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_addr;
    CData/*4:0*/ ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rd_addr;
    CData/*3:0*/ ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op;
    CData/*1:0*/ ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op;
    CData/*0:0*/ ysyx_25040109_top__DOT__cpu__DOT__idu_exu_reg_write;
    CData/*0:0*/ ysyx_25040109_top__DOT__cpu__DOT__idu_exu_jalr;
    CData/*0:0*/ ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid;
    CData/*0:0*/ ysyx_25040109_top__DOT__cpu__DOT__exu_idu_ready;
    CData/*1:0*/ ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_mem_op;
    CData/*0:0*/ ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_valid;
    CData/*0:0*/ ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready;
    CData/*4:0*/ ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_addr;
    CData/*0:0*/ ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_write;
    CData/*4:0*/ ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr;
    CData/*0:0*/ ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_write;
    CData/*0:0*/ ysyx_25040109_top__DOT__cpu__DOT__jump_flag_from_exu;
    CData/*0:0*/ __Vdly__ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid;
    CData/*0:0*/ __Vdly__ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid;
    CData/*0:0*/ __Vdly__ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_valid;
    CData/*0:0*/ __Vdly__ysyx_25040109_top__DOT__lsu_valid;
    CData/*1:0*/ __Vdly__ysyx_25040109_top__DOT__lsu_op;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __Vtrigrprev__TOP__rst;
    CData/*0:0*/ __VactContinue;
    VL_OUT(pc,31,0);
    VL_OUT(inst,31,0);
    VL_IN(p_count_number,31,0);
    VL_OUT(a0_out,31,0);
    IData/*31:0*/ ysyx_25040109_top__DOT__ifu_data;
    IData/*31:0*/ ysyx_25040109_top__DOT__lsu_addr;
    IData/*31:0*/ ysyx_25040109_top__DOT__lsu_wdata;
    IData/*31:0*/ ysyx_25040109_top__DOT__lsu_rdata;
    IData/*31:0*/ ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst;
    IData/*31:0*/ ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_pc;
    IData/*31:0*/ ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_data;
    IData/*31:0*/ ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_data;
    IData/*31:0*/ ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm;
    IData/*31:0*/ ysyx_25040109_top__DOT__cpu__DOT__idu_exu_pc;
    IData/*31:0*/ ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_addr;
    IData/*31:0*/ ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_wdata;
    IData/*31:0*/ ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_data;
    IData/*31:0*/ ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_data;
    IData/*31:0*/ ysyx_25040109_top__DOT__cpu__DOT__jump_addr_from_exu;
    IData/*31:0*/ ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc;
    IData/*31:0*/ ysyx_25040109_top__DOT__cpu__DOT__u_exu__DOT__alu_result;
    IData/*31:0*/ ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__i;
    IData/*31:0*/ __Vdly__ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc;
    IData/*31:0*/ __Vdly__ysyx_25040109_top__DOT__cpu__DOT__idu_exu_pc;
    IData/*31:0*/ __Vdly__ysyx_25040109_top__DOT__lsu_addr;
    IData/*31:0*/ __Vdly__ysyx_25040109_top__DOT__lsu_wdata;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 16> ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vysyx_25040109_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vysyx_25040109_top___024root(Vysyx_25040109_top__Syms* symsp, const char* v__name);
    ~Vysyx_25040109_top___024root();
    VL_UNCOPYABLE(Vysyx_25040109_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
