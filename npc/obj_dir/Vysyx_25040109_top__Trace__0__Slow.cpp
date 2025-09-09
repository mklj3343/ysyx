// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vysyx_25040109_top__Syms.h"


VL_ATTR_COLD void Vysyx_25040109_top___024root__trace_init_sub__TOP__0(Vysyx_25040109_top___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+61,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+62,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+63,"pc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+64,"inst",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+65,"p_count_number",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+66,"a0_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("ysyx_25040109_top ");
    tracep->declBit(c+61,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+62,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+63,"pc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+64,"inst",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+65,"p_count_number",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+66,"a0_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+6,"mem_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+7,"mem_wdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+1,"mem_rdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+67,"mem_wen",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+68,"mem_ren",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+8,"mem_funct3",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBus(c+63,"pc_internal",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+64,"inst_internal",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+9,"next_pc_internal",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("cpu ");
    tracep->declBus(c+9,"next_pc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+63,"pc_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+64,"inst_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+66,"a0_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+61,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+62,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+6,"mem_addr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+7,"mem_wdata",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+67,"mem_wen",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+68,"mem_ren",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+8,"mem_funct3",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBus(c+1,"mem_rdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+69,"STATE_FETCH_INST",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 0,0);
    tracep->declBus(c+70,"STATE_EXECUTE",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 0,0);
    tracep->declBit(c+10,"current_state",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+11,"next_state",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+12,"pc_current",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+13,"inst_reg",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+14,"rs1_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+7,"rs2_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+15,"imm",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+16,"alu_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+2,"load_data",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,"writeback_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+17,"is_load",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+18,"is_store",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+19,"reg_write_en",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+20,"inst_invalid",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+21,"rd_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+8,"funct3",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBit(c+22,"is_add",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+23,"is_lui",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+24,"is_jalr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+25,"is_csrrw",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+26,"csr_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 11,0);
    tracep->declBus(c+27,"csr_rdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declQuad(c+28,"mcycle_counter",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 63,0);
    tracep->declBit(c+10,"pc_update_en",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+4,"raddr1",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+5,"raddr2",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+71,"CSR_MCYCLE",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 11,0);
    tracep->declBus(c+72,"CSR_MCYCLEH",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 11,0);
    tracep->declBus(c+73,"CSR_MVENDORID",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 11,0);
    tracep->declBus(c+74,"CSR_MARCHID",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 11,0);
    tracep->declBit(c+30,"read_request",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+31,"is_addr_valid",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->pushNamePrefix("exu ");
    tracep->declBus(c+12,"pc",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+14,"rs1_data",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+7,"rs2_data",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+15,"imm",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+20,"inst_invalid",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+22,"is_add",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+23,"is_lui",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+24,"is_jalr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+16,"alu_result",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+9,"next_pc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+32,"alu_a",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+33,"alu_b",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+34,"alu_out",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+35,"jalr_target",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("idu ");
    tracep->declBus(c+13,"inst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+21,"rd_addr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+15,"imm",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+17,"is_load",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+18,"is_store",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+19,"reg_write_en",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+8,"funct3",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBit(c+20,"inst_invalid",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+22,"is_add",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+23,"is_lui",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+24,"is_jalr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+25,"is_csrrw",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+26,"csr_addr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 11,0);
    tracep->declBus(c+36,"opcode",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 6,0);
    tracep->declBit(c+37,"is_addi",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+38,"imm_u",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 19,0);
    tracep->declBus(c+26,"imm_i",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 11,0);
    tracep->declBus(c+39,"imm_s",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 11,0);
    tracep->declBus(c+40,"imm_u_ext",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+41,"imm_i_ext",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+42,"imm_s_ext",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pc_reg ");
    tracep->declBus(c+75,"WIDTH",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+76,"RESET_VAL",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBit(c+61,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+62,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+9,"din",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+12,"dout",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+10,"wen",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regfile ");
    tracep->declBus(c+77,"ADDR_WIDTH",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+75,"DATA_WIDTH",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
    tracep->declBus(c+66,"a0_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+61,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+62,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+12,"pc",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+3,"wdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+21,"waddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBit(c+43,"wen",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+4,"raddr1",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+5,"raddr2",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+14,"rdata1",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+7,"rdata2",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+44+i*1,"rf",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, true,(i+0), 31,0);
    }
    tracep->declBus(c+14,"rdata1_reg",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,"rdata2_reg",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("mem ");
    tracep->declBit(c+61,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+62,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+6,"mem_addr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+7,"mem_wdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+67,"mem_wen",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+68,"mem_ren",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+8,"mem_funct3",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBus(c+1,"mem_rdata",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+1,"mem_rdata_reg",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+60,"len",-1, FST_VD_IMPLICIT,FST_VT_VCD_INTEGER, false,-1, 31,0);
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void Vysyx_25040109_top___024root__trace_init_top(Vysyx_25040109_top___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root__trace_init_top\n"); );
    // Body
    Vysyx_25040109_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vysyx_25040109_top___024root__trace_full_top_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vysyx_25040109_top___024root__trace_chg_top_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vysyx_25040109_top___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vysyx_25040109_top___024root__trace_register(Vysyx_25040109_top___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vysyx_25040109_top___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vysyx_25040109_top___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vysyx_25040109_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vysyx_25040109_top___024root__trace_full_sub_0(Vysyx_25040109_top___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vysyx_25040109_top___024root__trace_full_top_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root__trace_full_top_0\n"); );
    // Init
    Vysyx_25040109_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_25040109_top___024root*>(voidSelf);
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vysyx_25040109_top___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vysyx_25040109_top___024root__trace_full_sub_0(Vysyx_25040109_top___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25040109_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25040109_top___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->ysyx_25040109_top__DOT__mem__DOT__mem_rdata_reg),32);
    bufp->fullIData(oldp+2,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__load_data),32);
    bufp->fullIData(oldp+3,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw)
                              ? ((0xb00U == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
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
                                              : 0U))))
                              : ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load)
                                  ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__load_data
                                  : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result))),32);
    bufp->fullCData(oldp+4,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__raddr1),5);
    bufp->fullCData(oldp+5,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__raddr2),5);
    bufp->fullIData(oldp+6,(vlSelf->ysyx_25040109_top__DOT__mem_addr),32);
    bufp->fullIData(oldp+7,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata2_reg),32);
    bufp->fullCData(oldp+8,((7U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                   >> 0xcU))),3);
    bufp->fullIData(oldp+9,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0)
                              ? ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_jalr)
                                  ? (0xfffffffeU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu__DOT__alu_out)
                                  : ((IData)(4U) + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current))
                              : ((IData)(4U) + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current))),32);
    bufp->fullBit(oldp+10,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state));
    bufp->fullBit(oldp+11,((1U & (~ (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state)))));
    bufp->fullIData(oldp+12,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current),32);
    bufp->fullIData(oldp+13,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg),32);
    bufp->fullIData(oldp+14,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata1_reg),32);
    bufp->fullIData(oldp+15,(((0x37U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg))
                               ? (0xfffff000U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)
                               : ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store)
                                   ? (((- (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                   >> 0x1fU))) 
                                       << 0xcU) | (
                                                   (0xfe0U 
                                                    & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                       >> 0x14U)) 
                                                   | (0x1fU 
                                                      & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                         >> 7U))))
                                   : (((- (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                   >> 0x1fU))) 
                                       << 0xcU) | (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                   >> 0x14U))))),32);
    bufp->fullIData(oldp+16,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__alu_result),32);
    bufp->fullBit(oldp+17,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load));
    bufp->fullBit(oldp+18,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store));
    bufp->fullBit(oldp+19,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu__DOT____VdfgTmp_h250803ec__0) 
                            | (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw))));
    bufp->fullBit(oldp+20,((1U & (~ (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0)))));
    bufp->fullCData(oldp+21,((0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                       >> 7U))),5);
    bufp->fullBit(oldp+22,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_add));
    bufp->fullBit(oldp+23,((0x37U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg))));
    bufp->fullBit(oldp+24,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_jalr));
    bufp->fullBit(oldp+25,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw));
    bufp->fullSData(oldp+26,((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                              >> 0x14U)),12);
    bufp->fullIData(oldp+27,(((0xb00U == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                          >> 0x14U))
                               ? (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter)
                               : ((0xb80U == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                              >> 0x14U))
                                   ? (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter 
                                              >> 0x20U))
                                   : ((0xf11U == (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                  >> 0x14U))
                                       ? 0x79737978U
                                       : ((0xf12U == 
                                           (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                            >> 0x14U))
                                           ? 0x17e14edU
                                           : 0U))))),32);
    bufp->fullQData(oldp+28,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__mcycle_counter),64);
    bufp->fullBit(oldp+30,((1U & ((~ (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state)) 
                                  | ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state) 
                                     & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0) 
                                        & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load)))))));
    bufp->fullBit(oldp+31,((0U != vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current)));
    bufp->fullIData(oldp+32,(((0x37U == (0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg))
                               ? 0U : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata1_reg)),32);
    bufp->fullIData(oldp+33,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_add)
                               ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rdata2_reg
                               : ((0x37U == (0x7fU 
                                             & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg))
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
                                             >> 0x14U)))))),32);
    bufp->fullIData(oldp+34,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu__DOT__alu_out),32);
    bufp->fullIData(oldp+35,((0xfffffffeU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu__DOT__alu_out)),32);
    bufp->fullCData(oldp+36,((0x7fU & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)),7);
    bufp->fullBit(oldp+37,((IData)((0x13U == (0x707fU 
                                              & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)))));
    bufp->fullIData(oldp+38,((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                              >> 0xcU)),20);
    bufp->fullSData(oldp+39,(((0xfe0U & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                         >> 0x14U)) 
                              | (0x1fU & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                          >> 7U)))),12);
    bufp->fullIData(oldp+40,((0xfffff000U & vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg)),32);
    bufp->fullIData(oldp+41,((((- (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                           >> 0x1fU))) 
                               << 0xcU) | (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                           >> 0x14U))),32);
    bufp->fullIData(oldp+42,((((- (IData)((vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                           >> 0x1fU))) 
                               << 0xcU) | ((0xfe0U 
                                            & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                               >> 0x14U)) 
                                           | (0x1fU 
                                              & (vlSelf->ysyx_25040109_top__DOT__cpu__DOT__inst_reg 
                                                 >> 7U))))),32);
    bufp->fullBit(oldp+43,(((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state) 
                            & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0) 
                               & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu__DOT____VdfgTmp_h250803ec__0) 
                                  | (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_csrrw))))));
    bufp->fullIData(oldp+44,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+45,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+46,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+47,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+48,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+49,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+50,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+51,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+52,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+53,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+54,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+55,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+56,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+57,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+58,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+59,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+60,(vlSelf->ysyx_25040109_top__DOT__mem__DOT__unnamedblk1__DOT__len),32);
    bufp->fullBit(oldp+61,(vlSelf->clk));
    bufp->fullBit(oldp+62,(vlSelf->rst));
    bufp->fullIData(oldp+63,(vlSelf->pc),32);
    bufp->fullIData(oldp+64,(vlSelf->inst),32);
    bufp->fullIData(oldp+65,(vlSelf->p_count_number),32);
    bufp->fullIData(oldp+66,(vlSelf->a0_out),32);
    bufp->fullBit(oldp+67,(((~ (IData)(vlSelf->rst)) 
                            & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state) 
                               & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0) 
                                  & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_store))))));
    bufp->fullBit(oldp+68,(((~ (IData)(vlSelf->rst)) 
                            & (((~ (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state)) 
                                | ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__current_state) 
                                   & ((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT____VdfgTmp_hf3066aec__0) 
                                      & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__is_load)))) 
                               & (0U != vlSelf->ysyx_25040109_top__DOT__cpu__DOT__pc_current)))));
    bufp->fullBit(oldp+69,(0U));
    bufp->fullBit(oldp+70,(1U));
    bufp->fullSData(oldp+71,(0xb00U),12);
    bufp->fullSData(oldp+72,(0xb80U),12);
    bufp->fullSData(oldp+73,(0xf11U),12);
    bufp->fullSData(oldp+74,(0xf12U),12);
    bufp->fullIData(oldp+75,(0x20U),32);
    bufp->fullIData(oldp+76,(0x80000000U),32);
    bufp->fullIData(oldp+77,(5U),32);
}
