`timescale 1ns / 1ps
module ifu_mem (
    input  wire        clk,
    input  wire        rst,
    input  wire [31:0] addr,
    output reg  [31:0] rdata,
    input  wire        valid,
    output reg         ready
);

    `ifndef SYNTHESIS
    import "DPI-C" function int verilog_pmem_read(input int addr, input int len);
    `endif

    reg        pend;
    reg [31:0] addr_q;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            rdata <= 32'h0;
            ready <= 1'b0;
            pend  <= 1'b0;
            addr_q<= 32'h0;
        end else begin
            ready <= 1'b0;

            if (!pend && valid) begin
                addr_q <= addr;
                pend   <= 1'b1;
            end

            if (pend) begin
                `ifndef SYNTHESIS
                    // 用局部变量打印“当拍”的读取结果
                    reg [31:0] r_next;
                    r_next = verilog_pmem_read(addr_q, 4);
                    rdata  <= r_next;
                    $display("IFU_MEM READ  addr=0x%08x  rdata=0x%08x", addr_q, r_next);
                `else
                    rdata  <= 32'h0;
                `endif
                ready <= 1'b1;
                pend  <= 1'b0;
            end
        end
    end

endmodule
