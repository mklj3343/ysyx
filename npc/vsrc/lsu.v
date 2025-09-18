`timescale 1ns / 1ps
module lsu (
    input  wire        clk,
    input  wire        rst,

    // 来自 EXU
    input  wire [31:0] addr,
    input  wire [31:0] wdata,
    input  wire [2:0]  mem_op,     // 000:NONE,001:LW,010:LBU,011:SW,100:SB
    input  wire        exu_valid,
    output reg         lsu_ready,
    input  wire [4:0]  rd_addr,

    // 到内存
    output reg  [31:0] mem_addr,
    output reg  [31:0] mem_wdata,
    input  wire [31:0] mem_rdata,
    output reg  [2:0]  mem_op_out,
    output reg         mem_valid,  // 脉冲
    input  wire        mem_ready,  // 下一拍返回

    // 回写到寄存器堆（仅对 load 有效）
    output reg  [4:0]  regfile_rd_addr,
    output reg  [31:0] regfile_rd_data,
    output reg         regfile_write
);
    // 只保留用到的枚举
    localparam [2:0] MEM_NONE = 3'b000,
                     MEM_LW   = 3'b001,
                     MEM_LBU  = 3'b010;


    // 简单两段式：IDLE -> WAIT_RESP
    reg        busy;          // 正在等待内存响应
    reg [2:0]  op_q;          // 锁存的 mem_op
    reg [4:0]  rd_q;          // 锁存的 rd

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            lsu_ready       <= 1'b1;

            mem_valid       <= 1'b0;
            mem_addr        <= 32'h0;
            mem_wdata       <= 32'h0;
            mem_op_out      <= MEM_NONE;

            regfile_write   <= 1'b0;
            regfile_rd_addr <= 5'h0;
            regfile_rd_data <= 32'h0;

            busy            <= 1'b0;
            op_q            <= MEM_NONE;
            rd_q            <= 5'h0;

        end else begin
            // 默认拉低“脉冲”与写回
            mem_valid     <= 1'b0;
            regfile_write <= 1'b0;

            if (!busy) begin
                // 空闲期：可以接受新的 EXU 请求
                lsu_ready <= 1'b1;
                if (exu_valid) begin
                    // 锁存请求，向内存打一拍
                    mem_addr   <= addr;
                    mem_wdata  <= wdata;
                    mem_op_out <= mem_op;
                    mem_valid  <= 1'b1;

                    op_q <= mem_op;
                    rd_q <= rd_addr;

                    // 对所有访存（含 store），进入等待响应状态；
                    // （对于 store，WAIT_RESP 只等一拍 ready，用于与内存模块对齐）
                    if (mem_op != MEM_NONE) begin
                        busy      <= 1'b1;
                        lsu_ready <= 1'b0;
                    end
                end

            end else begin
                // WAIT_RESP：等待 lsu_mem 拉起 ready（下一拍）
                lsu_ready <= 1'b0;

                if (mem_ready) begin
                    // 仅 load 需要写回
                    if (op_q == MEM_LW) begin
                        regfile_rd_addr <= rd_q;
                        regfile_rd_data <= mem_rdata;
                        regfile_write   <= 1'b1;
                    end else if (op_q == MEM_LBU) begin
                        regfile_rd_addr <= rd_q;
                        regfile_rd_data <= {24'h0, mem_rdata[7:0]};
                        regfile_write   <= 1'b1;
                    end
                    // 返回空闲
                    busy      <= 1'b0;
                    lsu_ready <= 1'b1;
                end
            end
        end
    end
endmodule
