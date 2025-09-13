module ysyx_25040109_mem (
    input clk,
    input rst,
    // IFU SimpleBus 接口
    input        ifu_reqValid,
    input [31:0] ifu_addr,
    output reg   ifu_respValid,
    output reg [31:0] ifu_rdata,
    // LSU SimpleBus 接口
    input        lsu_reqValid,
    input [31:0] lsu_addr,
    input        lsu_wen,
    input [31:0] lsu_wdata,
    input [3:0]  lsu_wmask,
    input [2:0]  lsu_rlen, 
    output reg   lsu_respValid,
    output reg [31:0] lsu_rdata
);

`ifndef SYNTHESIS
    import "DPI-C" function int verilog_pmem_read(input int addr,input int len);
    import "DPI-C" function void verilog_pmem_write(input int addr, input int data, input byte mask);
`endif



        reg [2:0] write_len;
    always @(*) begin
        case (lsu_wmask)
            4'b0001, 4'b0010, 4'b0100, 4'b1000: write_len = 1;

            4'b0011, 4'b1100:                   write_len = 2;

            4'b1111:                            write_len = 4;

            default:                            write_len = 0;
        endcase
    end


    always @(posedge clk) begin
        if (rst) begin
            ifu_respValid <= 0;
            lsu_respValid <= 0;
            ifu_rdata     <= 32'b0; // 复位时明确赋值
            lsu_rdata     <= 32'b0; // 复位时明确赋值
        end else begin
            // IFU端口: 只读，只有reqValid时工作
            ifu_respValid <= ifu_reqValid;
            if (ifu_reqValid) begin
`ifndef SYNTHESIS
                ifu_rdata <= verilog_pmem_read(ifu_addr,32'd4);
`else
                ifu_rdata <= 32'h0;  
`endif
            end else begin

            ifu_rdata <= ifu_rdata; 
        end


            lsu_respValid <= lsu_reqValid;
            if (lsu_reqValid) begin
                if (!lsu_wen) begin
`ifndef SYNTHESIS
                    lsu_rdata <= verilog_pmem_read(lsu_addr,{29'b0, lsu_rlen});
`else
                    lsu_rdata <= 32'h0;
`endif
                end else begin
`ifndef SYNTHESIS
                    verilog_pmem_write(lsu_addr, lsu_wdata, {5'b0,write_len});
`endif
                    lsu_rdata <= lsu_rdata; 
                end
            end else begin

            lsu_rdata <= lsu_rdata;
        end
        end
    end

endmodule

