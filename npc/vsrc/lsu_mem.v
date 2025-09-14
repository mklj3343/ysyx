`timescale 1ns / 1ps
module lsu_mem (
    input wire clk,
    input wire rst,
    input wire [31:0] addr,
    input wire [31:0] wdata,
    output reg [31:0] rdata,
    input wire [1:0] op, // 00: idle, 01: lw, 10: lbu, 11: sw
    input wire lsu_valid,
    output reg ready
);

    `ifndef SYNTHESIS
    import "DPI-C" function int verilog_pmem_read(input int addr, input int len);
    import "DPI-C" function void verilog_pmem_write(input int addr, input int data, input int len);
    `endif



    always @(posedge clk or posedge rst) begin
        if (rst) begin
            rdata <= 32'h0;
            ready <= 1'b1;

        end else if (lsu_valid) begin
            ready <= 1'b0;
            case (op)
                2'b01: begin // lw
                    `ifndef SYNTHESIS

                    rdata <= verilog_pmem_read(addr,4);
                    `else
                    rdata <= 32'h0;
                    `endif
                end
                2'b10: begin // lbu
                    `ifndef SYNTHESIS

                    rdata <= verilog_pmem_read(addr,1);
                    `else
                    rdata <= 32'h0;
                    `endif
                end
                2'b11: begin // sw
                    
                    `ifndef SYNTHESIS
                    verilog_pmem_write(addr, wdata, 4);
                    `endif
                end
                2'b00: begin // sb (重用 00 作为 sb，实际应为 10)
                    
                    `ifndef SYNTHESIS
                    verilog_pmem_write(addr, wdata, 1);
                    `endif
                end
                default: begin
                    rdata <= 32'h0;
                end
            endcase
            ready <= 1'b1;
        end else begin
            ready <= 1'b1;
        end
    end

endmodule


