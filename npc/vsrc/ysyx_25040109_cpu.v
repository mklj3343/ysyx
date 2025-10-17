module ysyx_25040109_cpu (
`ifndef SYNTHESIS
    output [31:0] next_pc,
    output [31:0] pc_out,
    output [31:0] inst_out,
    output [31:0] a0_out,
`endif
    input         clk,
    input         rst,
`ifdef SYNTHESIS
    input  [31:0] yosys_store_load,
`endif
    output [31:0] mem_addr,
    output [31:0] mem_wdata,
    output        mem_wen,
    output        mem_ren,
    output [2:0]  mem_funct3,
    input  [31:0] mem_rdata
);
    localparam STATE_FETCH_INST = 1'b0;
    localparam STATE_EXECUTE    = 1'b1;

    reg current_state;
    wire next_state;

    wire [31:0] pc_current;
    reg  [31:0] inst_reg;

    wire [31:0] inst_ifu;
    wire [4:0]  rd_addr_idu;
    wire [4:0]  rs1_addr_idu;
    wire [4:0]  rs2_addr_idu;
    wire [31:0] imm_idu;
    wire        reg_write_en_idu;
    wire [2:0]  funct3_idu;
    wire [6:0]  funct7_idu;
    wire        inst_invalid_idu;
    wire [11:0] csr_addr_idu;

    wire [31:0] rs1_data;
    wire [31:0] rs2_data;
    wire [31:0] result_exu;
    wire [4:0]  rd_addr_exu;
    wire        reg_write_en_exu;
    wire [31:0] next_pc_exu;
    wire        csr_we_exu;
    wire [31:0] csr_wdata_exu;

    wire [31:0] csr_rdata_reg;
    wire [31:0] mepc_reg;
    wire [31:0] mtvec_reg;

    wire [31:0] load_data_lsu;
    wire [31:0] writeback_data;
    wire [11:0] final_csr_waddr;
    wire [31:0] final_csr_wdata;
    wire        final_csr_we;

    reg trap_state;
    localparam S_NORMAL       = 1'b0;
    localparam S_TRAP_MCAUSE = 1'b1;

    wire is_stalled_by_trap = (trap_state == S_TRAP_MCAUSE);

    wire pc_wen = (current_state == STATE_EXECUTE) && !is_stalled_by_trap;

    ysyx_25040109_Reg #(.WIDTH(32), .RESET_VAL(32'h8000_0000)) pc_reg (
        .clk (clk),
        .rst (rst),
        .din (next_pc_exu),
        .dout(pc_current),
        .wen (pc_wen)
    );

    always @(posedge clk) begin
        if (rst) begin
            current_state <= STATE_FETCH_INST;
        end else begin
            current_state <= next_state;
        end
    end

    assign next_state = (current_state == STATE_FETCH_INST) ? STATE_EXECUTE : STATE_FETCH_INST;

    always @(posedge clk) begin
        if (rst) begin
            inst_reg <= 32'h0000_0013;
        end else if (current_state == STATE_FETCH_INST) begin
            inst_reg <= inst_ifu;
        end
    end

`ifndef SYNTHESIS
    assign pc_out   = pc_current;
    assign inst_out = inst_reg;
`endif

    ysyx_25040109_IFU ifu (
        .pc(pc_current),
`ifdef SYNTHESIS
        .yosys_inst_from_mem(mem_rdata),
`endif
        .inst_ifu(inst_ifu)
    );

    ysyx_25040109_IDU idu (
        .inst(inst_reg),
        .rd_addr(rd_addr_idu),
        .rs1_addr(rs1_addr_idu),
        .rs2_addr(rs2_addr_idu),
        .imm(imm_idu),
        .reg_write_en_idu(reg_write_en_idu),
        .funct3(funct3_idu),
        .funct7(funct7_idu),
        .inst_invalid(inst_invalid_idu),
        .csr_addr(csr_addr_idu)
    );

    wire [6:0] opcode = inst_reg[6:0];

    ysyx_25040109_RegisterFile #(5, 32) regfile (
        .pc(pc_current),
        .clk(clk),
        .rst(rst),
        .wdata(writeback_data),
        .waddr(rd_addr_exu),
        .wen(final_gpr_we),
        .raddr1(rs1_addr_idu),
        .raddr2(rs2_addr_idu),
        .rdata1(rs1_data),
        .rdata2(rs2_data),
`ifndef SYNTHESIS
        .a0_out(a0_out),
`endif
        .csr_we(final_csr_we),
        .csr_addr(final_csr_waddr),
        .csr_wdata(final_csr_wdata),
        .mepc_out(mepc_reg),
        .mtvec_out(mtvec_reg),
        .csr_rdata(csr_rdata_reg)
    );

    ysyx_25040109_EXU exu (
        .rs1_data(rs1_data),
        .rs2_data(rs2_data),
        .imm(imm_idu),
        .reg_write_in(reg_write_en_idu),
        .reg_write_en_out(reg_write_en_exu),
        .rd_addr(rd_addr_idu),
        .rs1_addr(rs1_addr_idu),
        .pc(pc_current),
        .opcode(opcode),
        .funct3(funct3_idu),
        .funct7(funct7_idu),
        .inst_invalid(inst_invalid_idu),
        .result(result_exu),
        .rd_addr_out(rd_addr_exu),
        .next_pc(next_pc_exu),
        .csr_addr(csr_addr_idu),
        .csr_rdata(csr_rdata_reg),
        .mepc(mepc_reg),
        .mtvec(mtvec_reg),
        .csr_we_out(csr_we_exu),
        .csr_wdata_out(csr_wdata_exu)
    );

    wire is_load  = (opcode == 7'b0000011) &&
                    (funct3_idu == 3'b000 || funct3_idu == 3'b001 || funct3_idu == 3'b010 ||
                     funct3_idu == 3'b100 || funct3_idu == 3'b101);
    wire is_store = (opcode == 7'b0100011);

    wire final_mem_we = is_store && !inst_invalid_idu && !is_stalled_by_trap;
    wire load_en = is_load && !inst_invalid_idu;

    ysyx_25040109_LSU lsu (
        .clk(clk),
        .rst(rst),
        .load_en(load_en),
        .store_en(final_mem_we),
        .funct3(funct3_idu),
        .addr(result_exu),
        .store_data(rs2_data),
`ifdef SYNTHESIS
        .yosys_store_load(yosys_store_load),
`endif
        .load_data(load_data_lsu)
    );

    wire is_ecall = (opcode == 7'b1110011) && (funct3_idu == 3'b000) && (csr_addr_idu == 12'h000) && !inst_invalid_idu;
    wire final_gpr_we = reg_write_en_exu && !is_stalled_by_trap;

    assign writeback_data = load_en ? load_data_lsu : result_exu;

    localparam CSR_MEPC   = 12'h341;
    localparam CSR_MCAUSE = 12'h342;

    assign final_csr_we = is_stalled_by_trap ? 1'b1 :
                          is_ecall          ? 1'b1 :
                          csr_we_exu;

    assign final_csr_waddr = is_stalled_by_trap ? CSR_MCAUSE :
                             is_ecall           ? CSR_MEPC   :
                             csr_addr_idu;

    assign final_csr_wdata = is_stalled_by_trap ? 32'd11 :
                             is_ecall           ? pc_current :
                             csr_wdata_exu;

    always @(posedge clk) begin
        if (rst) begin
            trap_state <= S_NORMAL;
        end else begin
            case (trap_state)
                S_NORMAL: begin
                    if (is_ecall) begin
                        trap_state <= S_TRAP_MCAUSE;
                    end
                end
                S_TRAP_MCAUSE: begin
                    trap_state <= S_NORMAL;
                end
                default: trap_state <= S_NORMAL;
            endcase
        end
    end

`ifndef SYNTHESIS
    import "DPI-C" function void difftest_skip_ref();
    import "DPI-C" function void itrace_print(int pc, int instruction_word, int instr_len_bytes, int p_count_number);
    import "DPI-C" function int printf_finish(input int inst);
`endif

    wire mem_read_request = (current_state == STATE_FETCH_INST) || load_en;

    assign mem_addr   = (current_state == STATE_FETCH_INST) ? pc_current : result_exu;
    assign mem_wdata  = rs2_data;
    assign mem_wen    = final_mem_we;
    assign mem_ren    = mem_read_request;
    assign mem_funct3 = (current_state == STATE_FETCH_INST) ? 3'b010 : funct3_idu;

`ifndef SYNTHESIS
    always @(posedge clk) begin
        if (final_mem_we || load_en || is_ecall || is_stalled_by_trap || opcode == 7'b1110011) begin
            difftest_skip_ref();
        end
    end

    always @(posedge clk) begin
        if (!rst) begin
            itrace_print(pc_current, inst_reg, 4, 0);
            if (printf_finish(inst_reg) == 0) begin
                $finish;
            end
        end
    end
`endif

`ifndef SYNTHESIS
    assign next_pc = next_pc_exu;
`endif
endmodule
