module ysyx_25040109_LSU (
    input         clk,
    input         rst,
    input         load_en,
    input         store_en,
    input  [2:0]  funct3,
    input  [31:0] addr,
    input  [31:0] store_data,
`ifdef SYNTHESIS
    input  [31:0] yosys_store_load,
`endif
    output reg [31:0] load_data
);
    reg [31:0] mem_data;

`ifndef SYNTHESIS
    import "DPI-C" function void verilog_pmem_read(input int addr, output int data);
    import "DPI-C" function void verilog_pmem_write(input int addr, input int data, input int len);
`endif

    always @(*) begin
        if (load_en) begin
`ifndef SYNTHESIS
            verilog_pmem_read(addr, mem_data);
`else
            mem_data = yosys_store_load;
`endif
            case (funct3)
                3'b000: load_data = {{24{mem_data[7]}},  mem_data[7:0]};
                3'b001: load_data = {{16{mem_data[15]}}, mem_data[15:0]};
                3'b010: load_data = mem_data;
                3'b100: load_data = {24'b0, mem_data[7:0]};
                3'b101: load_data = {16'b0, mem_data[15:0]};
                default: load_data = 32'b0;
            endcase
        end else begin
            mem_data  = 32'h0;
            load_data = 32'b0;
        end
    end

    always @(posedge clk) begin
        if (!rst && store_en) begin
`ifndef SYNTHESIS
            case (funct3)
                3'b000: verilog_pmem_write(addr, store_data, 1);
                3'b001: verilog_pmem_write(addr, store_data, 2);
                3'b010: verilog_pmem_write(addr, store_data, 4);
                default: ;
            endcase
`endif
        end
    end
endmodule
