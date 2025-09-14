module ysyx_25040109_mem (
    input clk,
    input rst,

    input  [31:0] mem_addr,   
    input  [31:0] mem_wdata,  
    input         mem_wen, 
    input         mem_ren,   
    input  [2:0]  mem_funct3, 
    output [31:0] mem_rdata   
);

`ifndef SYNTHESIS
    import "DPI-C" function void verilog_pmem_read(input int addr, output int data);
    import "DPI-C" function void verilog_pmem_write(input int addr, input int data, input int len);
`endif

    reg [31:0] mem_rdata_reg;


    always @(*) begin

        if (mem_ren) begin
`ifndef SYNTHESIS
            
            verilog_pmem_read(mem_addr, mem_rdata_reg);
`else

            mem_rdata_reg = 32'h0; 
`endif
        end else begin
            mem_rdata_reg = 32'h0;
        end
    end
    assign mem_rdata = mem_rdata_reg;


    `ifdef SYNTHESIS
    reg [31:0] len;
    `endif 
    always @(posedge clk ) begin
        if (!rst && mem_wen) begin
            `ifndef SYNTHESIS
            integer len;
            `endif 
            case (mem_funct3)
                3'b000: len = 1;  
                3'b010: len = 4;  
                default: len = 0;
            endcase
            if (len > 0) begin
`ifndef SYNTHESIS
                verilog_pmem_write(mem_addr, mem_wdata, len);
`else
                
`endif
            end
        end
    end

endmodule

