`timescale 1ns / 1ps
module ifu (
    input wire clk,
    input wire rst,
    input wire idu_ready,
    output reg [31:0] inst,
    output reg ifu_valid,



    output wire [31:0] ifu_addr,
    input wire [31:0] ifu_data,
    input wire ifu_ready,
    
    
    input wire jump_flag_from_exu,
    input wire [31:0] jump_addr_from_exu,
        
    output reg [31:0] inst_pc 
);
    reg [31:0] pc;
    assign ifu_addr = pc;


    always @(posedge clk or posedge rst) begin
        if (rst) begin
            pc <= 32'h80000000;
            inst_pc <= 32'h80000000;
            ifu_valid <= 1'b0;
            inst <= 32'h0;
        end else if (idu_ready && ifu_ready) begin

            inst_pc <= pc;
            inst <= ifu_data;
            ifu_valid <= 1'b1;

            if(jump_flag_from_exu)begin
                pc <= jump_addr_from_exu;
            end else begin
                pc <= pc + 4;
            end

        end else begin
            ifu_valid <= 1'b0;
        end
        
    end
endmodule

