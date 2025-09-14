`timescale 1ns / 1ps
module regfile (
    `ifndef SYNTHESIS
    output [31:0] a0_out,
    `endif
    input wire clk,
    input wire rst,
    input wire [4:0] rs1_addr,
    input wire [4:0] rs2_addr,
    output reg [31:0] rs1_data,
    output reg [31:0] rs2_data,
    input wire [4:0] exu_rd_addr,
    input wire [31:0] exu_rd_data,
    input wire exu_write,
    input wire [4:0] lsu_rd_addr,
    input wire [31:0] lsu_rd_data,
    input wire lsu_write
);
    reg [31:0] registers [0:15]; // RV32E: 16 GPRs

    integer i;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            for (i = 0; i < 16; i = i + 1) begin
                registers[i] <= 32'h0;
            end
            rs1_data <= 32'h0;
            rs2_data <= 32'h0;
        end else begin
            rs1_data <= (rs1_addr == 5'h0) ? 32'h0 : registers[rs1_addr[3:0]];
            rs2_data <= (rs2_addr == 5'h0) ? 32'h0 : registers[rs2_addr[3:0]];
            if (exu_write && exu_rd_addr != 5'h0) begin
                registers[exu_rd_addr[3:0]] <= exu_rd_data;
            end
            if (lsu_write && lsu_rd_addr != 5'h0) begin
                registers[lsu_rd_addr[3:0]] <= lsu_rd_data;
            end
        end
    end

    assign a0_out = registers[10];
endmodule


