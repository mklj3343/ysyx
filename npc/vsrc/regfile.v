`timescale 1ns / 1ps
module regfile (
    `ifndef SYNTHESIS
    output [31:0] a0_out,
    input  wire [31:0] wb_pc,
    `endif
    input  wire        clk,
    input  wire        rst,
    input  wire [4:0]  rs1_addr,
    input  wire [4:0]  rs2_addr,
    output wire [31:0] rs1_data,
    output wire [31:0] rs2_data,
    input  wire [4:0]  exu_rd_addr,
    input  wire [31:0] exu_rd_data,
    input  wire        exu_write,
    input  wire [4:0]  lsu_rd_addr,
    input  wire [31:0] lsu_rd_data,
    input  wire        lsu_write
);

    // RV32E: 16 个 GPR
    reg [31:0] registers [0:15];

    `ifndef SYNTHESIS
    import "DPI-C" function void update_cpu_state16(
        input int pc,
        input int r0,  input int r1,  input int r2,  input int r3,
        input int r4,  input int r5,  input int r6,  input int r7,
        input int r8,  input int r9,  input int r10, input int r11,
        input int r12, input int r13, input int r14, input int r15
    );

    reg [31:0] wb_pc_q;
    reg [31:0] wb_pc_qq;
    `endif

    integer i;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            for (i = 0; i < 16; i = i + 1) begin
                registers[i] <= 32'h0;
            end
            `ifndef SYNTHESIS
            wb_pc_q  <= 32'h0;
            wb_pc_qq <= 32'h0;
            `endif
        end else begin
            // 写回优先级：EXU > LSU
            if (exu_write && exu_rd_addr != 5'h0) begin
                registers[exu_rd_addr[3:0]] <= exu_rd_data;
            end
            if (lsu_write && lsu_rd_addr != 5'h0) begin
                registers[lsu_rd_addr[3:0]] <= lsu_rd_data;
            end

            `ifndef SYNTHESIS
            wb_pc_qq <= wb_pc_q;
            wb_pc_q  <= wb_pc;
            `endif
        end
    end

    // 读口 + 旁路；x0 恒为 0
    assign rs1_data = (rs1_addr == 5'h0) ? 32'h0 :
                      ((rs1_addr == lsu_rd_addr) && lsu_write) ? lsu_rd_data :
                      registers[rs1_addr[3:0]];

    assign rs2_data = (rs2_addr == 5'h0) ? 32'h0 :
                      ((rs2_addr == lsu_rd_addr) && lsu_write) ? lsu_rd_data :
                      registers[rs2_addr[3:0]];

    `ifndef SYNTHESIS
    assign a0_out = registers[10];
    `else
    wire _unused_a0_out = &registers[10];
    `endif

    `ifndef SYNTHESIS
    always @(negedge clk) begin
        update_cpu_state16(
            wb_pc_qq,
            registers[0],  registers[1],  registers[2],  registers[3],
            registers[4],  registers[5],  registers[6],  registers[7],
            registers[8],  registers[9],  registers[10], registers[11],
            registers[12], registers[13], registers[14], registers[15]
        );
    end
    `endif

endmodule
