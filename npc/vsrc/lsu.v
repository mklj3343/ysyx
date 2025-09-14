`timescale 1ns / 1ps
module lsu (
    input wire clk,
    input wire rst,
    input wire [31:0] addr,
    input wire [31:0] wdata,
    input wire [1:0] mem_op,
    input wire exu_valid,
    output reg lsu_ready,
    output reg [31:0] mem_addr,
    output reg [31:0] mem_wdata,
    input wire [31:0] mem_rdata,
    output reg [1:0] mem_op_out,
    output reg mem_valid,
    input wire mem_ready,
    output reg [4:0] regfile_rd_addr,
    output reg [31:0] regfile_rd_data,
    output reg regfile_write
);
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            lsu_ready <= 1'b1;
            mem_valid <= 1'b0;
            regfile_write <= 1'b0;
            mem_addr <= 32'h0;
            mem_wdata <= 32'h0;
            mem_op_out <= 2'h0;
            regfile_rd_addr <= 5'h0;
            regfile_rd_data <= 32'h0;
        end else if (exu_valid && mem_ready) begin
            lsu_ready <= 1'b0;
            mem_valid <= 1'b1;
            mem_addr <= addr;
            mem_wdata <= wdata;
            mem_op_out <= mem_op;
            regfile_write <= (mem_op == 2'h1 || mem_op == 2'h2); // lw, lbu
            regfile_rd_addr <= regfile_rd_addr; // From EXU
            regfile_rd_data <= (mem_op == 2'h1) ? mem_rdata :
                              (mem_op == 2'h2) ? {{24{1'b0}}, mem_rdata[7:0]} : 32'h0;
        end else begin
            lsu_ready <= 1'b1;
            mem_valid <= 1'b0;
            regfile_write <= 1'b0;
        end
    end
endmodule
