`timescale 1ns / 1ps

module ysyx_25040109_top (
    input wire clk,
    input wire rst,
    output wire [31:0] pc,
    output wire [31:0] inst,
    `ifndef SYNTHESIS
    input wire [31:0] p_count_number,
    `endif
    `ifdef SYNTHESIS
    input wire [31:0] yosys_store_load,
    `endif
    output wire [31:0] a0_out
);

    // IFU 访存接口
    wire [31:0] ifu_addr;
    wire [31:0] ifu_data;
    wire ifu_valid;
    wire ifu_ready;


    // LSU 访存接口
    wire [31:0] lsu_addr;
    wire [31:0] lsu_wdata;
    wire [31:0] lsu_rdata;
    wire [1:0] lsu_op;
    wire lsu_valid;
    wire lsu_ready;
    reg [31:0] inst_top;
    reg [31:0] ifu_idu_pc_top;
    reg [31:0] inst_pc_exu_top;

    // CPU 实例化
    minitv_cpu cpu (
        .inst_top(inst_top),
        .ifu_idu_pc_top(ifu_idu_pc_top),
        .inst_pc_exu_top(inst_pc_exu_top),
        .a0_out(a0_out),
        .clk(clk),
        .rst(rst),
        .ifu_addr(ifu_addr),
        .ifu_data(ifu_data),
        .ifu_valid(ifu_valid),
        .ifu_ready(ifu_ready),
        .lsu_addr(lsu_addr),
        .lsu_wdata(lsu_wdata),
        .lsu_rdata(lsu_rdata),
        .lsu_op(lsu_op),
        .lsu_valid(lsu_valid),
        .lsu_ready(lsu_ready)
    );

    // IFU 内存模块
    ifu_mem ifu_mem_inst (
        .clk(clk),
        .rst(rst),
        .addr(ifu_addr),
        .rdata(ifu_data),
        .valid(ifu_valid),
        .ready(ifu_ready)
    );

    // LSU 内存模块
    lsu_mem lsu_mem_inst (
        .clk(clk),
        .rst(rst),
        .addr(lsu_addr),
        .wdata(lsu_wdata),
        .rdata(lsu_rdata),
        .op(lsu_op),
        .lsu_valid(lsu_valid),
        .ready(lsu_ready)
    );

    // 输出连接
    assign pc = ifu_addr; // PC 从 IFU 的地址输出
    assign inst = ifu_data; // 指令从 IFU 的数据输出


    // 仿真功能
    `ifndef SYNTHESIS
    import "DPI-C" function void update_decode_state(int pc, int snpc, int dnpc, int inst);
    import "DPI-C" function void itrace_print(int pc, int instruction_word, int instr_len_bytes, int p_count_number);
    import "DPI-C" function void printf_finish();

    wire [31:0] next_pc_internal = ifu_addr + 4; // 假设顺序执行，next_pc 近似为 pc + 4

    always @(*) begin
        update_decode_state(pc, pc + 32'd4, next_pc_internal, inst);
    end

    always @(posedge clk) begin
        $display("inst:0x%x   ifu_idu_pc_top:0x%08x    inst_pc_exu_top:0x%08x    ",inst_top,ifu_idu_pc_top,inst_pc_exu_top);
        itrace_print(pc, inst, 4, p_count_number);

        if (inst == 32'h00100073) begin // ebreak 指令
            $display("enter finishi ,a0 decide ending\n");

           // $finish;
            printf_finish();
        end
    end
    `endif

endmodule

