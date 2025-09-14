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
    tracep->declBit(c+60,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+61,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+62,"pc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+63,"inst",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+64,"p_count_number",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+65,"a0_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("ysyx_25040109_top ");
    tracep->declBit(c+60,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+61,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+62,"pc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+63,"inst",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+64,"p_count_number",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+65,"a0_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+43,"ifu_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+44,"ifu_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+45,"ifu_valid",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+46,"ifu_ready",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+47,"lsu_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+48,"lsu_wdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+49,"lsu_rdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+50,"lsu_op",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBit(c+51,"lsu_valid",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+52,"lsu_ready",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+53,"inst_top",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,"ifu_idu_pc_top",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,"inst_pc_exu_top",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+54,"next_pc_internal",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("cpu ");
    tracep->declBus(c+65,"a0_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+53,"inst_top",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+1,"ifu_idu_pc_top",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+2,"inst_pc_exu_top",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+60,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+61,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+43,"ifu_addr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+44,"ifu_data",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+45,"ifu_valid",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+46,"ifu_ready",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+47,"lsu_addr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+48,"lsu_wdata",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+49,"lsu_rdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+50,"lsu_op",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBit(c+51,"lsu_valid",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+52,"lsu_ready",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+53,"ifu_idu_inst",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+45,"ifu_idu_valid",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+55,"idu_ifu_ready",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+1,"ifu_idu_pc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+3,"idu_exu_rs1_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+4,"idu_exu_rs2_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+5,"idu_exu_rs1_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+6,"idu_exu_rs2_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+7,"idu_exu_rd_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+8,"idu_exu_imm",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+9,"idu_exu_alu_op",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+10,"idu_exu_mem_op",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBit(c+11,"idu_exu_reg_write",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+12,"idu_exu_jalr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+2,"idu_exu_pc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+56,"idu_exu_valid",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+57,"exu_idu_ready",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+13,"exu_lsu_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+14,"exu_lsu_wdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+15,"exu_lsu_mem_op",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBit(c+58,"exu_lsu_valid",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+59,"lsu_exu_ready",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+16,"exu_regfile_rd_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+17,"exu_regfile_rd_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+18,"exu_regfile_write",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+19,"exu_lsu_rd_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+20,"lsu_regfile_rd_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+21,"lsu_regfile_rd_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+22,"lsu_regfile_write",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+23,"jump_flag_from_exu",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+24,"jump_addr_from_exu",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("u_exu ");
    tracep->declBit(c+60,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+61,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+3,"rs1_data",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+4,"rs2_data",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+7,"rd_addr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+8,"imm",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+9,"alu_op",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+10,"mem_op",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBit(c+11,"reg_write",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+12,"jalr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+56,"idu_valid",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+2,"inst_pc_from_idu",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+57,"exu_ready",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+13,"lsu_addr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+14,"lsu_wdata",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+15,"lsu_mem_op",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBit(c+58,"lsu_valid",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+59,"lsu_ready",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+19,"lsu_rd_addr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+16,"regfile_rd_addr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+17,"regfile_rd_data",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+18,"regfile_write",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+23,"jump_flag_from_exu",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+24,"jump_addr_from_exu",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+25,"alu_result",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_idu ");
    tracep->declBit(c+60,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+61,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+53,"inst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+45,"ifu_valid",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+55,"idu_ready",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+57,"exu_ready",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+1,"inst_pc_from_ifu",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+5,"rs1_addr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+6,"rs2_addr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+7,"rd_addr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+8,"imm",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+9,"alu_op",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+10,"mem_op",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBit(c+11,"reg_write",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+12,"jalr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+56,"idu_valid",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+2,"inst_pc_to_exu",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_ifu ");
    tracep->declBit(c+60,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+61,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+55,"idu_ready",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+53,"inst",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+45,"ifu_valid",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+43,"ifu_addr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+44,"ifu_data",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+46,"ifu_ready",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+23,"jump_flag_from_exu",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+24,"jump_addr_from_exu",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+1,"inst_pc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+43,"pc",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_lsu ");
    tracep->declBit(c+60,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+61,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+13,"addr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+14,"wdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+15,"mem_op",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBit(c+58,"exu_valid",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+59,"lsu_ready",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+19,"rd_addr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+47,"mem_addr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+48,"mem_wdata",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+49,"mem_rdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+50,"mem_op_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBit(c+51,"mem_valid",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+52,"mem_ready",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+20,"regfile_rd_addr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+21,"regfile_rd_data",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+22,"regfile_write",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_regfile ");
    tracep->declBus(c+65,"a0_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+2,"wb_pc",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+60,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+61,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+5,"rs1_addr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+6,"rs2_addr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+3,"rs1_data",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+4,"rs2_data",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+16,"exu_rd_addr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+17,"exu_rd_data",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+18,"exu_write",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+20,"lsu_rd_addr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+21,"lsu_rd_data",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+22,"lsu_write",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+26+i*1,"registers",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, true,(i+0), 31,0);
    }
    tracep->declBus(c+42,"i",-1, FST_VD_IMPLICIT,FST_VT_VCD_INTEGER, false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu_mem_inst ");
    tracep->declBit(c+60,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+61,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+43,"addr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+44,"rdata",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+45,"valid",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+46,"ready",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("lsu_mem_inst ");
    tracep->declBit(c+60,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+61,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+47,"addr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+48,"wdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+49,"rdata",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+50,"op",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBit(c+51,"lsu_valid",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+52,"ready",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
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
    bufp->fullIData(oldp+1,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_pc),32);
    bufp->fullIData(oldp+2,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_pc),32);
    bufp->fullIData(oldp+3,(((0U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_addr))
                              ? 0U : ((((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_addr) 
                                        == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr)) 
                                       & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_write))
                                       ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_data
                                       : ((((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_addr) 
                                            == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_addr)) 
                                           & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_write))
                                           ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_data
                                           : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
                                          [(0xfU & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_addr))])))),32);
    bufp->fullIData(oldp+4,(((0U == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_addr))
                              ? 0U : ((((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_addr) 
                                        == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr)) 
                                       & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_write))
                                       ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_data
                                       : ((((IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_addr) 
                                            == (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_addr)) 
                                           & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_write))
                                           ? vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_data
                                           : vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers
                                          [(0xfU & (IData)(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_addr))])))),32);
    bufp->fullCData(oldp+5,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs1_addr),5);
    bufp->fullCData(oldp+6,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rs2_addr),5);
    bufp->fullCData(oldp+7,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_rd_addr),5);
    bufp->fullIData(oldp+8,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_imm),32);
    bufp->fullCData(oldp+9,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_alu_op),4);
    bufp->fullCData(oldp+10,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_mem_op),2);
    bufp->fullBit(oldp+11,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_reg_write));
    bufp->fullBit(oldp+12,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_jalr));
    bufp->fullIData(oldp+13,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_addr),32);
    bufp->fullIData(oldp+14,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_wdata),32);
    bufp->fullCData(oldp+15,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_mem_op),2);
    bufp->fullCData(oldp+16,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_addr),5);
    bufp->fullIData(oldp+17,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_rd_data),32);
    bufp->fullBit(oldp+18,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_regfile_write));
    bufp->fullCData(oldp+19,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_rd_addr),5);
    bufp->fullCData(oldp+20,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_addr),5);
    bufp->fullIData(oldp+21,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_rd_data),32);
    bufp->fullBit(oldp+22,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_regfile_write));
    bufp->fullBit(oldp+23,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__jump_flag_from_exu));
    bufp->fullIData(oldp+24,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__jump_addr_from_exu),32);
    bufp->fullIData(oldp+25,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_exu__DOT__alu_result),32);
    bufp->fullIData(oldp+26,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[0]),32);
    bufp->fullIData(oldp+27,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[1]),32);
    bufp->fullIData(oldp+28,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[2]),32);
    bufp->fullIData(oldp+29,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[3]),32);
    bufp->fullIData(oldp+30,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[4]),32);
    bufp->fullIData(oldp+31,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[5]),32);
    bufp->fullIData(oldp+32,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[6]),32);
    bufp->fullIData(oldp+33,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[7]),32);
    bufp->fullIData(oldp+34,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[8]),32);
    bufp->fullIData(oldp+35,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[9]),32);
    bufp->fullIData(oldp+36,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[10]),32);
    bufp->fullIData(oldp+37,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[11]),32);
    bufp->fullIData(oldp+38,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[12]),32);
    bufp->fullIData(oldp+39,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[13]),32);
    bufp->fullIData(oldp+40,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[14]),32);
    bufp->fullIData(oldp+41,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[15]),32);
    bufp->fullIData(oldp+42,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__i),32);
    bufp->fullIData(oldp+43,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc),32);
    bufp->fullIData(oldp+44,(vlSelf->ysyx_25040109_top__DOT__ifu_data),32);
    bufp->fullBit(oldp+45,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_valid));
    bufp->fullBit(oldp+46,(vlSelf->ysyx_25040109_top__DOT__ifu_ready));
    bufp->fullIData(oldp+47,(vlSelf->ysyx_25040109_top__DOT__lsu_addr),32);
    bufp->fullIData(oldp+48,(vlSelf->ysyx_25040109_top__DOT__lsu_wdata),32);
    bufp->fullIData(oldp+49,(vlSelf->ysyx_25040109_top__DOT__lsu_rdata),32);
    bufp->fullCData(oldp+50,(vlSelf->ysyx_25040109_top__DOT__lsu_op),2);
    bufp->fullBit(oldp+51,(vlSelf->ysyx_25040109_top__DOT__lsu_valid));
    bufp->fullBit(oldp+52,(vlSelf->ysyx_25040109_top__DOT__lsu_ready));
    bufp->fullIData(oldp+53,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__ifu_idu_inst),32);
    bufp->fullIData(oldp+54,(((IData)(4U) + vlSelf->ysyx_25040109_top__DOT__cpu__DOT__u_ifu__DOT__pc)),32);
    bufp->fullBit(oldp+55,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_ifu_ready));
    bufp->fullBit(oldp+56,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__idu_exu_valid));
    bufp->fullBit(oldp+57,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_idu_ready));
    bufp->fullBit(oldp+58,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__exu_lsu_valid));
    bufp->fullBit(oldp+59,(vlSelf->ysyx_25040109_top__DOT__cpu__DOT__lsu_exu_ready));
    bufp->fullBit(oldp+60,(vlSelf->clk));
    bufp->fullBit(oldp+61,(vlSelf->rst));
    bufp->fullIData(oldp+62,(vlSelf->pc),32);
    bufp->fullIData(oldp+63,(vlSelf->inst),32);
    bufp->fullIData(oldp+64,(vlSelf->p_count_number),32);
    bufp->fullIData(oldp+65,(vlSelf->a0_out),32);
}
