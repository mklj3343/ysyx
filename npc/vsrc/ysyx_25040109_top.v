`timescale 1ns / 1ps
module ysyx_25040109_top (
    input  wire        clk,
    input  wire        rst,
    output wire [31:0] pc,
    output wire [31:0] inst,
    `ifndef SYNTHESIS
         /* verilator lint_off UNUSED */
    input  wire [31:0] p_count_number,
         /* verilator lint_off UNUSED */
    `endif
    `ifdef SYNTHESIS
    input  wire [31:0] yosys_store_load,
    `endif
    output wire [31:0] a0_out
);

    // IFU 接口
    wire [31:0] ifu_addr;
    wire [31:0] ifu_data;
    wire        ifu_valid;  // IFU->内存 valid（来自 IFU.mem_valid）
    wire        ifu_ready;

    // LSU 接口
    wire [31:0] lsu_addr;
    wire [31:0] lsu_wdata;
    wire [31:0] lsu_rdata;
    wire [2:0]  lsu_op;
    wire        lsu_valid;
    wire        lsu_ready;

    reg  [31:0] inst_top;
         /* verilator lint_off UNUSED */
    reg  [31:0] ifu_idu_pc_top;
         /* verilator lint_off UNUSED */
    reg  [31:0] inst_pc_exu_top;

    // -------------------------------
    // CPU 实例化
    // -------------------------------
    minitv_cpu cpu (
        .inst_top         (inst_top),
        .ifu_idu_pc_top   (ifu_idu_pc_top),
        .inst_pc_exu_top  (inst_pc_exu_top),
        .a0_out           (a0_out),
        .clk              (clk),
        .rst              (rst),
        .ifu_addr         (ifu_addr),
        .ifu_data         (ifu_data),
        .ifu_valid        (ifu_valid),
        .ifu_ready        (ifu_ready),
        .lsu_addr         (lsu_addr),
        .lsu_wdata        (lsu_wdata),
        .lsu_rdata        (lsu_rdata),
        .lsu_op           (lsu_op),
        .lsu_valid        (lsu_valid),
        .lsu_ready        (lsu_ready)
    );

    // -------------------------------
    // IFU 内存模块
    // -------------------------------
    ifu_mem ifu_mem_inst (
        .clk   (clk),
        .rst   (rst),
        .addr  (ifu_addr),
        .rdata (ifu_data),
        .valid (ifu_valid),
        .ready (ifu_ready)
    );

    // -------------------------------
    // LSU 内存模块
    // -------------------------------
    lsu_mem lsu_mem_inst (
        .clk       (clk),
        .rst       (rst),
        .addr      (lsu_addr),
        .wdata     (lsu_wdata),
        .rdata     (lsu_rdata),
        .op        (lsu_op),
        .lsu_valid (lsu_valid),
        .ready     (lsu_ready)
    );

    // -------------------------------
    // 输出信号
    // -------------------------------
    assign pc   = ifu_idu_pc_top;
    assign inst = inst_top;

    // 拉到顶层便于调试
    always @(*) begin
        inst_top       = cpu.ifu_idu_inst;
        ifu_idu_pc_top = cpu.ifu_idu_pc;
        inst_pc_exu_top= cpu.idu_exu_pc;
    end

    // -------------------------------
    // 仿真环境下的 DPI 调试接口
    // -------------------------------
    `ifndef SYNTHESIS
    import "DPI-C" function void update_decode_state(input int pc, input int snpc, input int dnpc, input int inst);
    import "DPI-C" function void itrace_print(input int pc, input int instruction_word, input int instr_len_bytes, input int p_count_number);
    import "DPI-C" function void printf_finish();

    wire [31:0] next_pc_internal = ifu_addr + 32'd4;

    // decode 状态更新
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            // no-op
        end else if (ifu_ready) begin
            update_decode_state(pc, pc + 32'd4, next_pc_internal, inst);
        end
    end

    // 指令追踪与结束条件
    reg finish_seen;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            finish_seen <= 1'b0;
        end else begin
            itrace_print(pc, inst, 4, p_count_number);
            if (!finish_seen && inst_top == 32'h0010_0073) begin // ebreak
                $display("enter finish , a0 decide ending");
                printf_finish();
                finish_seen <= 1'b1;
            end
        end
    end
    `endif

endmodule
