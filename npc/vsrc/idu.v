`timescale 1ns / 1ps
module idu (
    input wire clk,
    input wire rst,
    input wire [31:0] inst,
    input wire ifu_valid,
    output reg idu_ready,
    input wire exu_ready,

    input wire [31:0] inst_pc_from_ifu,

    output reg [4:0] rs1_addr,
    output reg [4:0] rs2_addr,
    output reg [4:0] rd_addr,
    output reg [31:0] imm,
    output reg [3:0] alu_op,
    output reg [1:0] mem_op,
    output reg reg_write,
    output reg jalr,
    output reg idu_valid,

    output reg [31:0] inst_pc_to_exu

);
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            idu_ready <= 1'b1;
            idu_valid <= 1'b0;
            rs1_addr <= 5'h0;
            rs2_addr <= 5'h0;
            rd_addr <= 5'h0;
            imm <= 32'h0;
            alu_op <= 4'h0;
            mem_op <= 2'h0;
            reg_write <= 1'b0;
            jalr <= 1'b0;
            inst_pc_to_exu <= 32'h0;
        end else if (ifu_valid && exu_ready) begin
            idu_ready <= 1'b0;
            idu_valid <= 1'b1;

            inst_pc_to_exu <= inst_pc_from_ifu;

            rs1_addr <= inst[19:15];
            rs2_addr <= inst[24:20];
            rd_addr <= inst[11:7];

            case (inst[6:0])
                7'b0110011: begin // R-type: add
                    alu_op <= 4'h1; // ADD
                    mem_op <= 2'h0;
                    reg_write <= 1'b1;
                    jalr <= 1'b0;
                    imm <= 32'h0;
                end
                7'b0010011: begin // I-type: addi
                    alu_op <= 4'h1; // ADD
                    mem_op <= 2'h0;
                    reg_write <= 1'b1;
                    jalr <= 1'b0;
                    imm <= {{20{inst[31]}}, inst[31:20]};
                end
                7'b0110111: begin // U-type: lui
                    alu_op <= 4'h2; // LUI
                    mem_op <= 2'h0;
                    reg_write <= 1'b1;
                    jalr <= 1'b0;
                    imm <= {inst[31:12], 12'h0};
                end
                7'b0000011: begin // I-type: lw, lbu
                    alu_op <= 4'h1; // ADD for address
                    mem_op <= (inst[14:12] == 3'h0) ? 2'h1 : 2'h2; // lw: 01, lbu: 10
                    reg_write <= 1'b1;
                    jalr <= 1'b0;
                    imm <= {{20{inst[31]}}, inst[31:20]};
                end
                7'b0100011: begin // S-type: sw, sb
                    alu_op <= 4'h1; // ADD for address
                    mem_op <= (inst[14:12] == 3'h2) ? 2'h3 : 2'h4; // sw: 11, sb: 10
                    reg_write <= 1'b0;
                    jalr <= 1'b0;
                    imm <= {{20{inst[31]}}, inst[31:25], inst[11:7]};
                end
                7'b1100111: begin // I-type: jalr
                    alu_op <= 4'h1; // ADD for address
                    mem_op <= 2'h0;
                    reg_write <= 1'b1;
                    jalr <= 1'b1;
                    imm <= {{20{inst[31]}}, inst[31:20]};
                end
                default: begin
                    alu_op <= 4'h0;
                    mem_op <= 2'h0;
                    reg_write <= 1'b0;
                    jalr <= 1'b0;
                    imm <= 32'h0;
                end
            endcase
        end else begin
            idu_valid <= 1'b0;
            idu_ready <= 1'b1;
        end
    end
endmodule


