//
// ysyx_25040109_top (统一内存接口版本)
//
module ysyx_25040109_top (
    input clk,
    input rst,
    output [31:0] pc,
    output [31:0] inst,
    `ifndef SYNTHESIS
    input [31:0] p_count_number,
    `endif
    `ifdef SYNTHESIS
    input [31:0] yosys_store_load, 
    `endif
    output [31:0] a0_out
);


    wire [31:0] mem_addr, mem_wdata, mem_rdata;
    wire        mem_wen, mem_ren;
    wire [2:0]  mem_funct3;
    wire [31:0] pc_internal, inst_internal, next_pc_internal;

    ysyx_25040109_cpu cpu (
        .clk(clk),
        .rst(rst),
        // 连接到统一的内存接口
        .mem_addr(mem_addr),
        .mem_wdata(mem_wdata),
        .mem_wen(mem_wen),
        .mem_ren(mem_ren),
        .mem_funct3(mem_funct3),
        .mem_rdata(mem_rdata),
        // 调试和仿真输出
        .pc_out(pc_internal),
        .inst_out(inst_internal),
        .a0_out(a0_out),
        .next_pc(next_pc_internal) // 连接到CPU的next_pc输出
    );

    ysyx_25040109_mem mem (
        .clk(clk),
        .rst(rst),
        // 连接到统一的内存接口
        .mem_addr(mem_addr),
        .mem_wdata(mem_wdata),
        .mem_wen(mem_wen),
        .mem_ren(mem_ren),
        .mem_funct3(mem_funct3),
        .mem_rdata(mem_rdata)
    );

    // 输出连接
    assign pc = pc_internal;
    assign inst = inst_internal;

    // 仿真功能（错误指令处理和程序结束判断）
    `ifndef SYNTHESIS
    import "DPI-C" function void update_decode_state(int pc, int snpc, int dnpc, int inst);
    import "DPI-C" function void itrace_print(int pc, int instruction_word, int instr_len_bytes, int p_count_number);
    import "DPI-C" function void printf_finish();

    // 注意：next_pc现在直接从CPU的输出端口获取
    always @(*) begin
        update_decode_state(pc, pc + 32'd4, next_pc_internal, inst); 
    end

    always @(posedge clk) begin
         itrace_print(pc, inst, 4, p_count_number); // 在CPU状态机驱动下，PC和inst可能不同步，itrace需谨慎使用
        if (inst == 32'h00100073) begin // ebreak指令
        itrace_print(pc, inst, 4, p_count_number);
            printf_finish();
        end
    end
    `endif

endmodule



