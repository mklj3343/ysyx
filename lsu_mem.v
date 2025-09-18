`timescale 1ns / 1ps
module lsu_mem (
    input  wire        clk,
    input  wire        rst,
    input  wire [31:0] addr,
    input  wire [31:0] wdata,
    output reg  [31:0] rdata,
    input  wire [2:0]  op,       // 000:NONE,001:LW,010:LBU,011:SW,100:SB
    input  wire        lsu_valid,
    output reg         ready
);
    `ifndef SYNTHESIS
    import "DPI-C" function int  verilog_pmem_read (input int addr, input int len);
    import "DPI-C" function void verilog_pmem_write(input int addr, input int data, input int len);
    `endif

    localparam [2:0] OP_LW  = 3'b001,
                     OP_LBU = 3'b010,
                     OP_SW  = 3'b011,
                     OP_SB  = 3'b100;

    // 与 IFU_MEM 一致：打一拍返回
    reg        pend;
    reg [31:0] addr_q;
    reg [31:0] wdata_q;
    reg [2:0]  op_q;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            rdata   <= 32'h0;
            ready   <= 1'b0;
            pend    <= 1'b0;
            addr_q  <= 32'h0;
            wdata_q <= 32'h0;
            op_q    <= 3'b000;

        end else begin
            ready <= 1'b0;

            // 锁存当拍请求
            if (!pend && lsu_valid) begin
                addr_q  <= addr;
                wdata_q <= wdata;
                op_q    <= op;
                pend    <= 1'b1;
            end

            // 下一拍真正访问存储器并拉起 ready
            if (pend) begin
                case (op_q)
                    OP_LW: begin
                        `ifndef SYNTHESIS
                            rdata <= verilog_pmem_read(addr_q, 4);
                        `else
                            rdata <= 32'h0;
                        `endif
                    end
                    OP_LBU: begin
                        `ifndef SYNTHESIS
                            rdata <= verilog_pmem_read(addr_q, 1);
                        `else
                            rdata <= 32'h0;
                        `endif
                    end
                    OP_SW: begin
                        `ifndef SYNTHESIS
                            verilog_pmem_write(addr_q, wdata_q, 4);
                        `endif
                    end
                    OP_SB: begin
                        `ifndef SYNTHESIS
                            verilog_pmem_write(addr_q, wdata_q, 1);
                        `endif
                    end
                    default: begin
                        // NONE
                    end
                endcase

                ready <= 1'b1;
                pend  <= 1'b0;
            end
        end
    end
endmodule
