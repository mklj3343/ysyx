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
    output reg   lsu_respValid,
    output reg [31:0] lsu_rdata
);

`ifndef SYNTHESIS
    import "DPI-C" function int verilog_pmem_read(input int addr);
    import "DPI-C" function void verilog_pmem_write(input int addr, input int data, input byte mask);
`endif



        reg [2:0] write_len;
    always @(*) begin
                case (lsu_wmask)
            // 写入1个字节 (sb) 的所有情况
            4'b0001, 4'b0010, 4'b0100, 4'b1000: write_len = 1;
            
            // 写入2个字节 (sh) 的所有情况
            4'b0011, 4'b1100:                     write_len = 2;
            
            // 写入4个字节 (sw) 的情况
            4'b1111:                               write_len = 4;
            
            // 默认情况，对于无效的掩码，长度为0
            default:                               write_len = 0;
        endcase
    end


    always @(posedge clk) begin
        if (rst) begin
            ifu_respValid <= 0;
            lsu_respValid <= 0;
        end else begin
            // IFU端口: 只读，只有reqValid时工作
            ifu_respValid <= ifu_reqValid;
            if (ifu_reqValid) begin
`ifndef SYNTHESIS
                ifu_rdata <= verilog_pmem_read(ifu_addr);
`else
                ifu_rdata <= 32'h0;  // 综合时占位
`endif
            end

            // LSU端口: 读/写，只有reqValid时工作
            lsu_respValid <= lsu_reqValid;
            if (lsu_reqValid) begin
                if (!lsu_wen) begin
`ifndef SYNTHESIS
                    lsu_rdata <= verilog_pmem_read(lsu_addr);
`else
                    lsu_rdata <= 32'h0;
`endif
                end else begin
`ifndef SYNTHESIS
                    verilog_pmem_write(lsu_addr, lsu_wdata, {5'b0,write_len});
`endif
                end
            end
        end
    end

endmodule

