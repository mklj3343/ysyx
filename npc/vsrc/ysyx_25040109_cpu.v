module ysyx_25040109_cpu (
`ifndef SYNTHESIS
    output [31:0] next_pc,
    output [31:0] pc_out,
    output [31:0] inst_out,
    output [31:0] a0_out,
`endif
    input clk,
    input rst,
    // IFU SimpleBus 接口
    output        ifu_reqValid,
    output [31:0] ifu_addr,
    input         ifu_respValid,
    input  [31:0] ifu_rdata,
    // LSU SimpleBus 接口
    output        lsu_reqValid,
    output [31:0] lsu_addr,
    output        lsu_wen,
    output [31:0] lsu_wdata,
    output [3:0]  lsu_wmask,
    input         lsu_respValid,
    input  [31:0] lsu_rdata
);

    localparam S_FETCH     = 2'b00;
    localparam S_WAIT_INST = 2'b01;
    localparam S_EXEC      = 2'b10;
    localparam S_WAIT_MEM  = 2'b11;
    reg [1:0] state;

    reg [31:0] inst_reg;     // 指令寄存器
    reg [31:0] load_data;    // load数据 (extend后)
    reg        fetch_en;
    reg        lsu_en;

    wire [31:0] pc_current;
    wire [31:0] rs1_data, rs2_data, imm;
    wire [31:0] alu_result;
    wire [31:0] writeback_data;
    wire        is_load, is_store;
    wire        reg_write_en;
    wire        inst_invalid;
    wire [4:0]  rd_addr;
    wire [2:0]  funct3;
    wire        is_add, is_lui, is_jalr, is_csrrw;
    wire [11:0] csr_addr;
    wire [31:0] csr_rdata;
    reg  [63:0] mcycle_counter;

    wire fetch_done;
    wire [31:0] ifu_inst;
    wire lsu_done;
    wire [31:0] lsu_rdata_internal;  // 从LSU的rdata


    wire [7:0] selected_byte; // 用于存放选择出的字节
    reg  [7:0] selected_byte_reg;

    // 字节选择器 (Byte Selector) - 组合逻辑
    always @(*) begin
        case (alu_result[1:0])
            2'b00:   selected_byte_reg = lsu_rdata_internal[7:0];
            2'b01:   selected_byte_reg = lsu_rdata_internal[15:8];
            2'b10:   selected_byte_reg = lsu_rdata_internal[23:16];
            2'b11:   selected_byte_reg = lsu_rdata_internal[31:24];
            default: selected_byte_reg = 8'h00; // 默认值，理论上不会到达
        endcase
    end
    assign selected_byte = selected_byte_reg;


    always @(posedge clk) begin
        if (rst) begin
            mcycle_counter <= 64'd0;
            state <= S_FETCH;
            fetch_en <= 0;
            lsu_en <= 0;
        end else begin
            mcycle_counter <= mcycle_counter + 1;
            case (state)
                S_FETCH: begin
                    fetch_en <= 1;
                    state <= S_WAIT_INST;
                end
                S_WAIT_INST: begin
                    fetch_en <= 0;
                    if (fetch_done) begin
                        inst_reg <= ifu_inst;
                        state <= S_EXEC;
                    end
                end
                S_EXEC: begin
                    if (inst_invalid) begin  // 无效指令，直接下一条
                        state <= S_FETCH;
                    end else if (is_load || is_store) begin
                        lsu_en <= 1;
                        state <= S_WAIT_MEM;
                    end else begin
                        state <= S_FETCH;
                    end
                end
                S_WAIT_MEM: begin
                    lsu_en <= 0;
                    if (lsu_done) begin
                        if (is_load) begin
                            case (funct3)
                                3'b010: load_data <= lsu_rdata_internal;  // lw
                                 // lbu
                                 3'b100: load_data <= {24'b0, selected_byte};
 // lbu
                                default: load_data <= 32'b0;
                            endcase
                        end
                        state <= S_FETCH;
                    end
                end
            endcase
        end
    end


/*

always @(*) begin
    $display("next:0x%08x  current:0x%08x  inst:0x%08x\n",next_pc,pc_current,inst_out);
end
*/
`ifndef SYNTHESIS
    assign pc_out = pc_current;
    assign inst_out = inst_reg;
`endif

    // PC 寄存器
    wire pc_update_en = ((state == S_EXEC) && !(is_load || is_store)) || ((state == S_WAIT_MEM) && lsu_done);
    ysyx_25040109_Reg #(.WIDTH(32), .RESET_VAL(32'h80000000)) pc_reg (
        .clk(clk),
        .rst(rst),
        .din(next_pc),
        .dout(pc_current),
        .wen(pc_update_en)
    );

    // IDU 模块
    ysyx_25040109_IDU idu (
        .inst(inst_reg),
        .rd_addr(rd_addr),
        .imm(imm),
        .is_load(is_load),
        .is_store(is_store),
        .reg_write_en(reg_write_en),
        .funct3(funct3),
        .inst_invalid(inst_invalid),
        .is_add(is_add),
        .is_lui(is_lui),
        .is_jalr(is_jalr),
        .is_csrrw(is_csrrw),
        .csr_addr(csr_addr)
    );

    // EXU 模块
    ysyx_25040109_EXU exu (
        .pc(pc_current),
        .rs1_data(rs1_data),
        .rs2_data(rs2_data),
        .imm(imm),
        .alu_result(alu_result),
        .next_pc(next_pc),
        .inst_invalid(inst_invalid),
        .is_add(is_add),
        .is_lui(is_lui),
        .is_jalr(is_jalr)
    );

    localparam CSR_MCYCLE  = 12'hB00;
    localparam CSR_MCYCLEH = 12'hB80;
    assign csr_rdata = (csr_addr == CSR_MCYCLE) ? mcycle_counter[31:0] :
                       (csr_addr == CSR_MCYCLEH) ? mcycle_counter[63:32] : 32'h0;

    assign writeback_data = is_csrrw ? csr_rdata :
                            is_load ? load_data : alu_result;

    // 寄存器堆
    wire reg_wen = ((state == S_EXEC) && reg_write_en && !inst_invalid && !(is_load || is_store)) ||
                   ((state == S_WAIT_MEM) && lsu_done && reg_write_en && !inst_invalid);
    ysyx_25040109_RegisterFile #(.ADDR_WIDTH(5), .DATA_WIDTH(32)) regfile (
        .pc(pc_current),
        .clk(clk),
        .rst(rst),
        .wdata(writeback_data),
        .waddr(rd_addr),
        .wen(reg_wen),
        .raddr1(inst_reg[19:15]),  // 不再提前选择，使用inst_reg
        .raddr2(inst_reg[24:20]),
        .rdata1(rs1_data),
        .rdata2(rs2_data)
`ifndef SYNTHESIS
        ,.a0_out(a0_out)
`endif
    );

    // 实例化IFU
    ysyx_25040109_IFU ifu (
        .clk(clk),
        .rst(rst),
        .fetch_en(fetch_en),
        .pc(pc_current),
        .fetch_done(fetch_done),
        .inst(ifu_inst),
        .ifu_reqValid(ifu_reqValid),
        .ifu_addr(ifu_addr),
        .ifu_respValid(ifu_respValid),
        .ifu_rdata(ifu_rdata)
    );

    // 实例化LSU
    ysyx_25040109_LSU lsu (
        .clk(clk),
        .rst(rst),
        .lsu_en(lsu_en),
        .is_load(is_load),
        .is_store(is_store),
        .funct3(funct3),
        .addr(alu_result),
        .wdata_in(rs2_data),
        .lsu_done(lsu_done),
        .rdata(lsu_rdata_internal),
        .lsu_reqValid(lsu_reqValid),
        .lsu_addr(lsu_addr),
        .lsu_wen(lsu_wen),
        .lsu_wdata(lsu_wdata),
        .lsu_wmask(lsu_wmask),
        .lsu_respValid(lsu_respValid),
        .lsu_rdata(lsu_rdata)
    );

endmodule
