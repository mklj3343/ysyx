module ysyx_25040109_IFU (
    input  [31:0] pc,
`ifdef SYNTHESIS
    input  [31:0] yosys_inst_from_mem,
`endif
    output [31:0] inst_ifu
);
    wire is_pc_valid = (pc >= 32'h8000_0000) && (pc <= 32'h87FF_FFFF);
    reg [31:0] inst_from_mem;

`ifndef SYNTHESIS
    import "DPI-C" function void verilog_pmem_read(input int addr, output int data);
`endif

    always @(*) begin
        if (is_pc_valid) begin
`ifndef SYNTHESIS
            verilog_pmem_read(pc, inst_from_mem);
`else
            inst_from_mem = yosys_inst_from_mem;
`endif
        end else begin
            inst_from_mem = 32'h0000_0013; // NOP
        end
    end

    assign inst_ifu = inst_from_mem;
endmodule
