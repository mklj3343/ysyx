`timescale 1ns / 1ps
module ifu (
    input  wire        clk,
    input  wire        rst,

    // 下游 IDU 的就绪
    input  wire        idu_ready,

    // IFU -> IDU
    output reg  [31:0] inst,
    output reg         ifu_valid,   // 送给 IDU 的 valid（仅在指令已经到手时打一拍）

    // IFU -> IFU_MEM
    output wire [31:0] ifu_addr,    // 取指地址
    input  wire [31:0] ifu_data,    // 内存返回的指令数据
    input  wire        ifu_ready,   // 内存数据有效，当拍脉冲
    output reg         mem_valid,   // 发给内存的请求 valid（脉冲）

    // 跳转重定向（来自 EXU）
    input  wire        jump_flag_from_exu,
    input  wire [31:0] jump_addr_from_exu,

    // 对外观测的指令 PC
    output reg  [31:0] inst_pc
);

    reg [31:0] pc;
    assign ifu_addr = pc;

    // IFU 内部缓冲/握手
    reg [31:0] inst_buf;
    reg        have_inst;     // 已经拿到一条待发给 IDU 的指令
    reg        req_inflight;  // 有一个发往内存的请求在途

    // 重定向打拍
    reg        redirect_pending;
    reg [31:0] redirect_addr_q;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            pc                <= 32'h80000000;
            inst_pc           <= 32'h80000000;
            inst              <= 32'h0;
            ifu_valid         <= 1'b0;

            mem_valid         <= 1'b0;
            have_inst         <= 1'b0;
            req_inflight      <= 1'b0;

            redirect_pending  <= 1'b0;
            redirect_addr_q   <= 32'h0;

        end else begin
            // 默认不给内存拉 valid（脉冲式）
            mem_valid <= 1'b0;
            // 默认不给 IDU 拉 valid（脉冲式）
            ifu_valid <= 1'b0;

            // 1) 接收来自 EXU 的重定向请求
            if (jump_flag_from_exu) begin
                redirect_pending <= 1'b1;
                redirect_addr_q  <= jump_addr_from_exu;
                have_inst        <= 1'b0;     // flush 缓存指令
            end

            // 2) 若无在途请求，且有重定向待处理
            if (redirect_pending && !req_inflight) begin
                pc               <= redirect_addr_q;
                redirect_pending <= 1'b0;
                have_inst        <= 1'b0;
            end

            // 3) 没有在途请求 && 没有待发指令 && 下游 ready
            if (!have_inst && !req_inflight && idu_ready) begin
                mem_valid    <= 1'b1;
                req_inflight <= 1'b1;
            end

            // 4) 等待内存返回
            if (req_inflight && ifu_ready) begin
                if (redirect_pending) begin
                    pc               <= redirect_addr_q;
                    redirect_pending <= 1'b0;
                end else begin
                    inst_buf  <= ifu_data;
                    inst_pc   <= pc;
                    have_inst <= 1'b1;
                    pc        <= pc + 32'd4;
                end
                req_inflight <= 1'b0;
            end

            // 5) 把指令交给 IDU
            if (have_inst && idu_ready && !redirect_pending && !jump_flag_from_exu) begin
                inst      <= inst_buf;
                ifu_valid <= 1'b1;
                have_inst <= 1'b0;
            end
        end
    end

endmodule
