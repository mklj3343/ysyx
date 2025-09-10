module ysyx_25040109_top (
    input clk,
    input rst,
    output [31:0] pc,
    output [31:0] inst,
    `ifndef SYNTHESIS
    input [31:0] p_count_number,
    `endif
    `ifdef SYNTHESIS
    input [31:0] yosys_store_load, 
    `endif
    output [31:0] a0_out
);


    wire [31:0] ifu_raddr,ifu_rdata;
    wire [31:0] lsu_addr,lsu_wdata,lsu_rdata;
    wire lsu_wen;
    wire [3:0] lsu_wmask;

    wire [31:0] pc_internal, inst_internal, next_pc_internal;

    ysyx_25040109_cpu cpu (
        .clk(clk),
        .rst(rst),
   
        .ifu_raddr(ifu_raddr),
        .ifu_rdata(ifu_rdata),
        .lsu_addr(lsu_addr),
        .lsu_wen(lsu_wen),
        .lsu_wdata(lsu_wdata),
        .lsu_rdata(lsu_rdata),
        .lsu_wmask(lsu_wmask),
        .pc_out(pc_internal),
        .inst_out(inst_internal),
        .a0_out(a0_out),
        .next_pc(next_pc_internal) // 连接到CPU的next_pc输出
    );

    ysyx_25040109_mem mem (
        .clk(clk),
        .rst(rst),

        .ifu_raddr(ifu_raddr),
        .ifu_rdata(ifu_rdata),
        .lsu_addr(lsu_addr),
        .lsu_wen(lsu_wen),
        .lsu_wdata(lsu_wdata),
        .lsu_wmask(lsu_wmask),
        .lsu_rdata(lsu_rdata)
    );


    assign pc = pc_internal;
    assign inst = inst_internal;


    `ifndef SYNTHESIS
    import "DPI-C" function void update_decode_state(int pc, int snpc, int dnpc, int inst);
    import "DPI-C" function void itrace_print(int pc, int instruction_word, int instr_len_bytes, int p_count_number);
    import "DPI-C" function void printf_finish();

 
    always @(*) begin
        update_decode_state(pc, pc + 32'd4, next_pc_internal, inst); 
    end

    always @(posedge clk) begin
         itrace_print(pc, inst, 4, p_count_number); 
        if (inst == 32'h00100073) begin 
        itrace_print(pc, inst, 4, p_count_number);
            printf_finish();
        end
    end
    `endif

endmodule



