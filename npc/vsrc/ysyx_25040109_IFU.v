// Instruction Fetch Unit (IFU)
// 功能：取指令
// - 从内存读取指令
// - PC地址验证
module ysyx_25040109_IFU (
    input [31:0] pc,
    `ifdef SYNTHESIS
    input [31:0] yosys_inst_from_mem,
    `endif
    output [31:0] inst_ifu
);
    // PC有效性检查（RAM地址范围）
    wire is_pc_valid = (pc >= 32'h80000000) && (pc <= 32'h87FFFFFF);

    reg [31:0] inst_from_mem;

    `ifndef SYNTHESIS
    // DPI-C函数：从物理内存读取
    import "DPI-C" function void verilog_pmem_read(input int addr, output int data);
    `endif

    // 组合逻辑：读取当前PC的指令
    always @(*) begin
        if (is_pc_valid) begin
            `ifndef SYNTHESIS
            verilog_pmem_read(pc, inst_from_mem);
            `else
            inst_from_mem = yosys_inst_from_mem;
            `endif
        end else begin
            inst_from_mem = 32'h00000013; // 无效地址返回NOP
        end
    end

    assign inst_ifu = inst_from_mem;

endmodule
