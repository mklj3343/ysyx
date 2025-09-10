module ysyx_25040109_mem (
    input clk,
    input rst,

    input [31:0] ifu_raddr,
    output reg [31:0] ifu_rdata,
    input [31:0] lsu_addr,
    input lsu_wen,
    input [31:0] lsu_wdata,
    input [3:0] lsu_wmask,
    output reg [31:0] lsu_rdata

);

`ifndef SYNTHESIS
    import "DPI-C" function int verilog_pmem_read(input int addr);
    import "DPI-C" function void verilog_pmem_write(input int addr, input int data, input int len);
`endif

    

    always @(posedge clk) begin
        if(!rst && ifu_raddr != 32'h0)begin
            `ifndef SYNTHESIS
            ifu_rdata <= verilog_pmem_read(ifu_raddr);
            `else
            ifu_rdata <= 32'h0;
            `endif 
        end
    end

    always @(posedge clk) begin
            if (!rst) begin
                if (lsu_wen) begin
                    integer len;
                    case (lsu_wmask)
                        4'b1111: len = 4; 
                        4'b0001, 4'b0010, 4'b0100, 4'b1000: len = 1;  
                        default: len = 0;
                    endcase
                    if (len > 0) begin
    `ifndef SYNTHESIS
                        verilog_pmem_write(lsu_addr, lsu_wdata, len);
    `else
                        
    `endif
                    end
                end else begin
    `ifndef SYNTHESIS
                    if(ifu_raddr != 32'h0)
                    lsu_rdata <= verilog_pmem_read(lsu_addr);
    `else
                    lsu_rdata <= 32'h0;
    `endif
                end
            end
        end
endmodule

