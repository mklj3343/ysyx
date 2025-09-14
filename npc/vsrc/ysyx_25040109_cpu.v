module ysyx_25040109_cpu (
    `ifndef SYNTHESIS
    output [31:0] next_pc,
    output [31:0] pc_out,      
    output [31:0] inst_out,   
    output [31:0] a0_out,      
    `endif

    input clk,
    input rst,

    output [31:0] mem_addr,   
    output [31:0] mem_wdata,   
    output        mem_wen,     
    output        mem_ren,     
    output [2:0]  mem_funct3, 
    input  [31:0] mem_rdata    
);

    localparam STATE_FETCH_INST = 1'b0;
    localparam STATE_EXECUTE    = 1'b1;

    reg  current_state;
    wire next_state;

    // CPU内部信号
    `ifdef SYNTHESIS
    wire [31:0] next_pc;
    `endif
    wire [31:0] pc_current;
    reg  [31:0] inst_reg; // 指令寄存器，锁存取回的指令

    wire [31:0] rs1_data, rs2_data, imm;
    wire [31:0] alu_result;
    reg  [31:0] load_data;
    wire [31:0] writeback_data;
    wire        is_load, is_store;
    wire        reg_write_en;
    wire        inst_invalid;
    wire [3:0]  rd_addr;
    wire [2:0]  funct3;
    wire        is_add, is_lui, is_jalr;

    `ifndef SYNTHESIS
    assign pc_out = pc_current;
    assign inst_out = inst_reg;
    `endif

    wire pc_update_en = (current_state == STATE_EXECUTE);
    ysyx_25040109_Reg #(.WIDTH(32), .RESET_VAL(32'h80000000)) pc_reg (
        .clk(clk),
        .rst(rst),
        .din(next_pc),
        .dout(pc_current),
        .wen(pc_update_en)
    );
    
    always @(posedge clk ) begin
        if (rst) begin
            current_state <= STATE_FETCH_INST;
        end else begin
            current_state <= next_state;
        end
    end

    assign next_state = (current_state == STATE_FETCH_INST) ? STATE_EXECUTE : STATE_FETCH_INST;
    
    always @(posedge clk ) begin
        if (!rst && current_state == STATE_FETCH_INST) begin
            inst_reg <= mem_rdata;
        end
    end

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
        .is_jalr(is_jalr)
    );

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



    assign mem_addr = (current_state == STATE_FETCH_INST) ? pc_current : alu_result;
    assign mem_wdata  = rs2_data;
    

    wire read_request = (current_state == STATE_FETCH_INST) || 
                       ((current_state == STATE_EXECUTE) && is_load && !inst_invalid);

    wire is_addr_valid = (mem_addr >= 32'h80000000);
    

    assign mem_ren = !rst && read_request && is_addr_valid;


    assign mem_wen = !rst && (current_state == STATE_EXECUTE) && is_store && !inst_invalid;
    
    assign mem_funct3 = funct3;

    always @(*) begin
        load_data = 32'b0;
        case (funct3)
            3'b010: load_data = mem_rdata;              // LW
            3'b100: load_data = {24'b0, mem_rdata[7:0]}; // LBU
            default: ;
        endcase
    end

    assign writeback_data = is_load ? load_data : alu_result;

    wire [3:0] raddr1 = (current_state == STATE_FETCH_INST) ? mem_rdata[18:15] : inst_reg[18:15];
    wire [3:0] raddr2 = (current_state == STATE_FETCH_INST) ? mem_rdata[23:20] : inst_reg[23:20];

    ysyx_25040109_RegisterFile #(.ADDR_WIDTH(4), .DATA_WIDTH(32)) regfile (
        .pc(pc_current),
        .clk(clk),
        .rst(rst),
        .wdata(writeback_data),
        .waddr(rd_addr),
        .wen((current_state == STATE_EXECUTE) && reg_write_en && !inst_invalid),
        .raddr1(raddr1),
        .raddr2(raddr2),
        .rdata1(rs1_data),
        `ifndef SYNTHESIS
        .a0_out(a0_out),
        `endif
        .rdata2(rs2_data)
    );

endmodule
