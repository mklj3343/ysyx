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
    wire [4:0]  rd_addr;
    wire [2:0]  funct3;
    wire        is_add, is_lui, is_jalr,is_csrrw;

    wire [11:0] csr_addr;
    wire [31:0] csr_rdata;
    reg  [63:0] mcycle_counter;


    always @(posedge clk) begin
        if(rst)begin
            mcycle_counter <= 64'd0;
        end else begin
            mcycle_counter <= mcycle_counter + 1;
        end
    end

`ifndef SYNTHESIS
    assign pc_out = pc_current;
    assign inst_out = inst_reg;
`endif

    // PC 寄存器
    wire pc_update_en = (current_state == STATE_EXECUTE);
    ysyx_25040109_Reg #(.WIDTH(32), .RESET_VAL(32'h80000000)) pc_reg (
        .clk(clk),
        .rst(rst),
        .din(next_pc),
        .dout(pc_current),
        .wen(pc_update_en)
    );

    // 状态机
    always @(posedge clk) begin
        if (rst) begin
            current_state <= STATE_FETCH_INST;
        end else begin
            current_state <= next_state;
        end
    end

    assign next_state = (current_state == STATE_FETCH_INST) ? STATE_EXECUTE : STATE_FETCH_INST;

    // 指令锁存
    always @(posedge clk) begin
        if (!rst && current_state == STATE_FETCH_INST) begin
            inst_reg <= mem_rdata;
        end
    end

    // 提前选择读地址：在 FETCH 状态使用 mem_rdata 的 rs1/rs2
    wire [4:0] raddr1 = (current_state == STATE_FETCH_INST) ? mem_rdata[19:15] : inst_reg[19:15];
    wire [4:0] raddr2 = (current_state == STATE_FETCH_INST) ? mem_rdata[24:20] : inst_reg[24:20];

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
        
    localparam CSR_MCYCLE     = 12'hB00 ;
    localparam CSR_MCYCLEH    = 12'hB80 ;
    localparam CSR_MVENDORID  = 12'hF11;
    localparam CSR_MARCHID    = 12'hF12 ;

    assign csr_rdata =  (csr_addr == CSR_MCYCLE)    ? mcycle_counter[31:0] :
                        (csr_addr == CSR_MCYCLEH )  ? mcycle_counter[63:32] :
                        (csr_addr == CSR_MVENDORID) ? 32'h79737978 :
                        (csr_addr == CSR_MARCHID)   ? 32'h17e14ed :  32'h0;

    // 内存接口
    assign mem_addr = (current_state == STATE_FETCH_INST) ? pc_current : alu_result;
    assign mem_wdata = rs2_data;

    wire read_request = (current_state == STATE_FETCH_INST) ||
                       ((current_state == STATE_EXECUTE) && is_load && !inst_invalid);
    wire is_addr_valid = (pc_current != 32'h00000000);
    assign mem_ren = !rst && read_request && is_addr_valid;
    assign mem_wen = !rst && (current_state == STATE_EXECUTE) && is_store && !inst_invalid;
    assign mem_funct3 = funct3;

    // 加载数据处理
    always @(*) begin
        load_data = 32'b0;
        case (funct3)
            3'b010: load_data = mem_rdata;              
            3'b100: load_data = {24'b0, mem_rdata[7:0]}; 
            default: ;
        endcase
    end

    assign writeback_data =is_csrrw ? csr_rdata :
                            is_load ? load_data : alu_result;

    // 寄存器堆实例化
    ysyx_25040109_RegisterFile #(.ADDR_WIDTH(5), .DATA_WIDTH(32)) regfile (
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
