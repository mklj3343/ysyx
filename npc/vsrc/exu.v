`timescale 1ns / 1ps
module exu (
    input wire clk,
    input wire rst,
    input wire [31:0] rs1_data,
    input wire [31:0] rs2_data,
    input wire [4:0] rd_addr,
    input wire [31:0] imm,
    input wire [3:0] alu_op,
    input wire [1:0] mem_op,
    input wire reg_write,
    input wire jalr,
    input wire idu_valid,

    input wire [31:0] inst_pc_from_idu,

    output reg exu_ready,
    output reg [31:0] lsu_addr,
    output reg [31:0] lsu_wdata,
    output reg [1:0] lsu_mem_op,
    output reg lsu_valid,
    input wire lsu_ready,
    output reg [4:0] regfile_rd_addr,
    output reg [31:0] regfile_rd_data,
    output reg regfile_write,

    output reg jump_flag_from_exu,
    output reg [31:0] jump_addr_from_exu
);


    reg [31:0] alu_result;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            exu_ready <= 1'b1;
            lsu_valid <= 1'b0;
            regfile_write <= 1'b0;
            lsu_addr <= 32'h0;
            lsu_wdata <= 32'h0;
            lsu_mem_op <= 2'h0;
            regfile_rd_addr <= 5'h0;
            regfile_rd_data <= 32'h0;
            jump_addr_from_exu <= 32'b0;
            jump_flag_from_exu <= 1'b0;
        end else if (idu_valid && lsu_ready) begin
            exu_ready <= 1'b0;
            lsu_valid <= (mem_op != 2'h0);
            lsu_mem_op <= mem_op;
            lsu_wdata <= rs2_data;
            regfile_rd_addr <= rd_addr;


                        
            alu_result <= (alu_op == 4'h1) ? (rs1_data + imm) : imm;

            if (jalr) begin
                jump_flag_from_exu <= 1'b1;
                jump_addr_from_exu <= alu_result & 32'hFFFFFFFE; 
            end else begin
                jump_flag_from_exu <= 1'b0;
                jump_addr_from_exu <= 32'h0; // 其他指令不跳转
            end
                        
            regfile_write <= reg_write && (mem_op == 2'h0);

            case (alu_op)
                4'h1: begin // ADD
                    lsu_addr <= alu_result;
                    if(jalr)begin
                       regfile_rd_data <= inst_pc_from_idu + 4; 
                    end else begin
                        regfile_rd_data <= alu_result;
                    end
                end
                4'h2: begin // LUI
                    regfile_rd_data <= imm;
                end
                default: begin
                    regfile_rd_data <= 32'h0;
                end
            endcase
        end else begin
            exu_ready <= 1'b1;
            lsu_valid <= 1'b0;
            regfile_write <= 1'b0;
            jump_flag_from_exu <= 1'b0; 
        end
    end
endmodule

