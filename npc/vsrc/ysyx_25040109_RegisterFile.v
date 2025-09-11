module ysyx_25040109_RegisterFile #(
    parameter ADDR_WIDTH = 5,
    parameter DATA_WIDTH = 32
) (
`ifndef SYNTHESIS
    output [DATA_WIDTH-1:0] a0_out,
`endif
    input                   clk,
    input                   rst,
    input  [31:0]           pc,
    input  [DATA_WIDTH-1:0] wdata,
    input  [ADDR_WIDTH-1:0] waddr,
    input                   wen,
    input  [ADDR_WIDTH-1:0] raddr1,
    input  [ADDR_WIDTH-1:0] raddr2,
    output  [DATA_WIDTH-1:0] rdata1,
    output [DATA_WIDTH-1:0] rdata2
);


    (* ram_style = "block" *) reg [DATA_WIDTH-1:0] rf[0:15];

    
    reg [DATA_WIDTH-1:0] rdata1_reg;
    reg [DATA_WIDTH-1:0] rdata2_reg;


    always @(posedge clk) begin
        
        if (wen && waddr[4:0] != 5'b0 && waddr[4:0] <= 5'd15) begin
            rf[waddr[3:0]] <= wdata;
        end
    end


    
    always @(posedge clk) begin
        if (rst) begin
            rdata1_reg <= 32'h0;
            rdata2_reg <= 32'h0;
        end else begin
            rdata1_reg <= (raddr1 == 5'b0) ? 32'b0 : rf[raddr1[3:0]];
            rdata2_reg <= (raddr2 == 5'b0) ? 32'b0 : rf[raddr2[3:0]];
        end
    end
    
    assign rdata1 = rdata1_reg;
    assign rdata2 = rdata2_reg;

`ifndef SYNTHESIS
    assign a0_out = rf[10];
`endif

`ifndef SYNTHESIS
    import "DPI-C" function void update_cpu_state(input int unsigned pc, input int unsigned regs[]);
    always @(*) begin
        update_cpu_state(pc, rf);
    end
`endif

endmodule

