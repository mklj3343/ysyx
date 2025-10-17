module ysyx_25040109_RegisterFile #(parameter ADDR_WIDTH = 5, parameter DATA_WIDTH = 32) (
    input  [31:0] pc,
    input         clk,
    input         rst,
    input  [DATA_WIDTH-1:0] wdata,
    input  [ADDR_WIDTH-1:0] waddr,
    input         wen,
    input  [ADDR_WIDTH-1:0] raddr1,
    input  [ADDR_WIDTH-1:0] raddr2,
    output [DATA_WIDTH-1:0] rdata1,
    output [DATA_WIDTH-1:0] rdata2,
`ifndef SYNTHESIS
    output [DATA_WIDTH-1:0] a0_out,
`endif
    input                    csr_we,
    input  [11:0]            csr_addr,
    input  [DATA_WIDTH-1:0]  csr_wdata,
    output reg [DATA_WIDTH-1:0] mepc_out,
    output reg [DATA_WIDTH-1:0] mtvec_out,
    output [DATA_WIDTH-1:0]  csr_rdata
);
    reg [DATA_WIDTH-1:0] rf [31:0];
    reg [DATA_WIDTH-1:0] mstatus;
    reg [DATA_WIDTH-1:0] mepc;
    reg [DATA_WIDTH-1:0] mcause;
    reg [DATA_WIDTH-1:0] mtvec;

    localparam CSR_MSTATUS = 12'h300;
    localparam CSR_MTVEC   = 12'h305;
    localparam CSR_MEPC    = 12'h341;
    localparam CSR_MCAUSE  = 12'h342;

`ifndef SYNTHESIS
    import "DPI-C" function void update_cpu_state(input int unsigned pc, input int unsigned regs[]);
    always @(*) begin
        update_cpu_state(pc, rf);
    end
`endif

    always @(posedge clk) begin
        if (wen && waddr != 5'b0) begin
            rf[waddr] <= wdata;
        end
    end

    assign rdata1 = (raddr1 == 5'b0) ? 32'b0 : rf[raddr1];
    assign rdata2 = (raddr2 == 5'b0) ? 32'b0 : rf[raddr2];

`ifndef SYNTHESIS
    assign a0_out = rf[10];
`endif

    assign csr_rdata = (csr_addr == CSR_MSTATUS) ? mstatus :
                       (csr_addr == CSR_MTVEC)   ? mtvec   :
                       (csr_addr == CSR_MEPC)    ? mepc    :
                       (csr_addr == CSR_MCAUSE)  ? mcause  :
                       32'h0;

    always @(*) begin
        mepc_out  = mepc;
        mtvec_out = mtvec;
    end

`ifndef SYNTHESIS
    integer i;
    initial begin
        for (i = 0; i < 32; i = i + 1) begin
            rf[i] = 0;
        end
    end
`endif

    always @(posedge clk) begin
        if (rst) begin
            mstatus <= 32'h1800;
            mtvec   <= 32'h0;
            mepc    <= 32'h0;
            mcause  <= 32'h0;
        end else if (csr_we) begin
            case (csr_addr)
                CSR_MSTATUS: mstatus <= csr_wdata;
                CSR_MTVEC:   mtvec   <= csr_wdata;
                CSR_MEPC:    mepc    <= csr_wdata;
                CSR_MCAUSE:  mcause  <= csr_wdata;
                default:;
            endcase
        end
    end
endmodule
