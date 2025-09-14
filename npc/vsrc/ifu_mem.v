`timescale 1ns / 1ps
module ifu_mem (
    input wire clk,
    input wire rst,
    input wire [31:0] addr,
    output reg [31:0] rdata,
    input wire valid,
    output reg ready
);

    `ifndef SYNTHESIS
    import "DPI-C" function int verilog_pmem_read(input int addr, input int len);
    `endif

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            rdata <= 32'h0;
            ready <= 1'b1;
        end else if (valid) begin
            ready <= 1'b0;
            `ifndef SYNTHESIS
            rdata <= verilog_pmem_read(addr, 4);
           // rdata <= verilog_pmem_read(32'h80000000, 4);
            $display("rdata:0x%08x\n",rdata);
            `else
            rdata <= 32'h0; // 综合时返回 0
            `endif
            ready <= 1'b1;
        end else begin
            ready <= 1'b1;
        end
    end

endmodule

