`timescale 1ns / 1ps

// CPU 主模块
module minitv_cpu (
    output reg [31:0] a0_out,
    output reg [31:0] inst_top,
    output reg [31:0] ifu_idu_pc_top,
    output reg [31:0] inst_pc_exu_top,

    input wire clk,
    input wire rst,
    // IFU 访存接口
    output wire [31:0] ifu_addr,
    input wire [31:0] ifu_data,
    output wire ifu_valid,
    input wire ifu_ready,
    // LSU 访存接口
    output wire [31:0] lsu_addr,
    output wire [31:0] lsu_wdata,
    input wire [31:0] lsu_rdata,
    output wire [1:0] lsu_op, // 00: idle, 01: load, 10: store
    output wire lsu_valid,
    input wire lsu_ready
);


    always @(*) begin
        inst_top = ifu_idu_inst;
        ifu_idu_pc_top = ifu_idu_pc;
        inst_pc_exu_top = idu_exu_pc;
    
    end 



    assign ifu_valid = ifu_idu_valid;

    // IFU 到 IDU 的接口
    wire [31:0] ifu_idu_inst;
    wire ifu_idu_valid;
    wire idu_ifu_ready;
    wire [31:0] ifu_idu_pc; 

    // IDU 到 EXU 的接口
    wire [31:0] idu_exu_rs1_data;
    wire [31:0] idu_exu_rs2_data;
    wire [4:0] idu_exu_rs1_addr;
    wire [4:0] idu_exu_rs2_addr;
    wire [4:0] idu_exu_rd_addr;
    wire [31:0] idu_exu_imm;
    wire [3:0] idu_exu_alu_op;
    wire [1:0] idu_exu_mem_op;
    wire idu_exu_reg_write;
    wire idu_exu_jalr;
    wire [31:0] idu_exu_pc; 
    wire idu_exu_valid;
    wire exu_idu_ready;

    // EXU 到 LSU 的接口
    wire [31:0] exu_lsu_addr;
    wire [31:0] exu_lsu_wdata;
    wire [1:0] exu_lsu_mem_op;
    wire exu_lsu_valid;
    wire lsu_exu_ready;

    // EXU 到 Regfile 的接口
    wire [4:0] exu_regfile_rd_addr;
    wire [31:0] exu_regfile_rd_data;
    wire exu_regfile_write;


    // LSU 到 Regfile 的接口
    wire [4:0] lsu_regfile_rd_addr;
    wire [31:0] lsu_regfile_rd_data;
    wire lsu_regfile_write;

        
    wire jump_flag_from_exu;
    wire [31:0] jump_addr_from_exu;

    // 实例化模块
    ifu u_ifu (
        .clk(clk),
        .rst(rst),
        .idu_ready(idu_ifu_ready),
        .inst(ifu_idu_inst),
        .ifu_valid(ifu_idu_valid),
        .ifu_addr(ifu_addr),
        .ifu_data(ifu_data),
        .ifu_ready(ifu_ready),
        .jump_flag_from_exu(jump_flag_from_exu),
        .jump_addr_from_exu(jump_addr_from_exu),
        .inst_pc(ifu_idu_pc)
    );

    idu u_idu (
        .clk(clk),
        .rst(rst),
        .inst(ifu_idu_inst),
        .ifu_valid(ifu_idu_valid),
        .idu_ready(idu_ifu_ready),
        .exu_ready(exu_idu_ready),
        .inst_pc_from_ifu(ifu_idu_pc),
        .rs1_addr(idu_exu_rs1_addr),
        .rs2_addr(idu_exu_rs2_addr),
        .rd_addr(idu_exu_rd_addr),
        .imm(idu_exu_imm),
        .alu_op(idu_exu_alu_op),
        .mem_op(idu_exu_mem_op),
        .reg_write(idu_exu_reg_write),
        .jalr(idu_exu_jalr),
        .idu_valid(idu_exu_valid),
        .inst_pc_to_exu(idu_exu_pc) 
    );

    exu u_exu (
        .clk(clk),
        .rst(rst),
        .rs1_data(idu_exu_rs1_data),
        .rs2_data(idu_exu_rs2_data),
        .rd_addr(idu_exu_rd_addr),
        .imm(idu_exu_imm),
        .alu_op(idu_exu_alu_op),
        .mem_op(idu_exu_mem_op),
        .reg_write(idu_exu_reg_write),
        .jalr(idu_exu_jalr),
        .idu_valid(idu_exu_valid),
        .inst_pc_from_idu(idu_exu_pc),
        .exu_ready(exu_idu_ready),
        .lsu_addr(exu_lsu_addr),
        .lsu_wdata(exu_lsu_wdata),
        .lsu_mem_op(exu_lsu_mem_op),
        .lsu_valid(exu_lsu_valid),
        .lsu_ready(lsu_exu_ready),
        .regfile_rd_addr(exu_regfile_rd_addr),
        .regfile_rd_data(exu_regfile_rd_data),
        .regfile_write(exu_regfile_write),
        .jump_flag_from_exu(jump_flag_from_exu),
        .jump_addr_from_exu(jump_addr_from_exu)
    );

    lsu u_lsu (
        .clk(clk),
        .rst(rst),
        .addr(exu_lsu_addr),
        .wdata(exu_lsu_wdata),
        .mem_op(exu_lsu_mem_op),
        .exu_valid(exu_lsu_valid),
        .lsu_ready(lsu_exu_ready),
        .mem_addr(lsu_addr),
        .mem_wdata(lsu_wdata),
        .mem_rdata(lsu_rdata),
        .mem_op_out(lsu_op),
        .mem_valid(lsu_valid),
        .mem_ready(lsu_ready),
        .regfile_rd_addr(lsu_regfile_rd_addr),
        .regfile_rd_data(lsu_regfile_rd_data),
        .regfile_write(lsu_regfile_write)
    );

    regfile u_regfile (
        .a0_out(a0_out),
        .clk(clk),
        .rst(rst),
        .rs1_addr(idu_exu_rs1_addr),
        .rs2_addr(idu_exu_rs2_addr),
        .rs1_data(idu_exu_rs1_data),
        .rs2_data(idu_exu_rs2_data),
        .exu_rd_addr(exu_regfile_rd_addr),
        .exu_rd_data(exu_regfile_rd_data),
        .exu_write(exu_regfile_write),
        .lsu_rd_addr(lsu_regfile_rd_addr),
        .lsu_rd_data(lsu_regfile_rd_data),
        .lsu_write(lsu_regfile_write)
    );

endmodule

// IFU 模块


// IDU 模块

// EXU 模块

// LSU 模块


// Regfile 模块
