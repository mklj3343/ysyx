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
    CData/*0:0*/ ysyx_25040109_top__DOT__cpu__DOT__current_state;
    CData/*0:0*/ ysyx_25040109_top__DOT__cpu__DOT__next_state;
    CData/*0:0*/ ysyx_25040109_top__DOT__cpu__DOT__is_load;
    CData/*0:0*/ ysyx_25040109_top__DOT__cpu__DOT__is_store;
    CData/*0:0*/ ysyx_25040109_top__DOT__cpu__DOT__is_add;
    CData/*0:0*/ ysyx_25040109_top__DOT__cpu__DOT__is_jalr;
    CData/*0:0*/ ysyx_25040109_top__DOT__cpu__DOT__is_csrrw;
    CData/*4:0*/ ysyx_25040109_top__DOT__cpu__DOT__raddr1;
    CData/*4:0*/ ysyx_25040109_top__DOT__cpu__DOT__raddr2;
    CData/*0:0*/ ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0;
    CData/*0:0*/ ysyx_25040109_top__DOT__cpu__DOT__idu__DOT____VdfgTmp_h250803ec__0;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    VL_OUT(pc,31,0);
    VL_OUT(inst,31,0);
    VL_IN(p_count_number,31,0);
    VL_OUT(a0_out,31,0);
    IData/*31:0*/ ysyx_25040109_top__DOT__mem_addr;
    IData/*31:0*/ ysyx_25040109_top__DOT__next_pc_internal;
    IData/*31:0*/ ysyx_25040109_top__DOT__cpu__DOT__pc_current;
    IData/*31:0*/ ysyx_25040109_top__DOT__cpu__DOT__inst_reg;
    IData/*31:0*/ ysyx_25040109_top__DOT__cpu__DOT__alu_result;
    IData/*31:0*/ ysyx_25040109_top__DOT__cpu__DOT__load_data;
    IData/*31:0*/ ysyx_25040109_top__DOT__cpu__DOT__exu__DOT__alu_out;
    IData/*31:0*/ ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata1_reg;
    IData/*31:0*/ ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata2_reg;
    IData/*31:0*/ ysyx_25040109_top__DOT__mem__DOT__mem_rdata_reg;
    IData/*31:0*/ ysyx_25040109_top__DOT__mem__DOT__unnamedblk1__DOT__len;
    IData/*31:0*/ __Vtask_ysyx_25040109_top__DOT__mem__DOT__verilog_pmem_read__5__data;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    QData/*63:0*/ ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter;
    VlUnpacked<IData/*31:0*/, 16> ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

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
