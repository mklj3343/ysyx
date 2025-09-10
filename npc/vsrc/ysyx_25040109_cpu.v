module ysyx_25040109_cpu (
`ifndef SYNTHESIS
    output [31:0] next_pc,
    output [31:0] pc_out,      
    output [31:0] inst_out,  
    output [31:0] a0_out,      
`endif
    input clk,
    input rst,
    
    output [31:0] ifu_raddr,
    input  [31:0] ifu_rdata,
    output [31:0] lsu_addr,
    output lsu_wen,
    output [31:0] lsu_wdata,
    output [3:0]  lsu_wmask,
    input [31:0]  lsu_rdata
    
    );

    localparam STATE_FETCH_INST = 1'b0;
    localparam STATE_EXECUTE    = 1'b1;


    reg  current_state;
    wire next_state;


`ifdef SYNTHESIS
    wire [31:0] next_pc;
`endif
    wire [31:0] pc_current;
    reg  [31:0] inst;
    wire ifu_valid;

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

    wire lsu_start = (current_state == STATE_EXECUTE) && (is_load || is_store) && ifu_valid;
    wire lsu_done;



    always @(posedge clk) begin
        if(rst)begin
            mcycle_counter <= 64'd0;
        end else begin
            mcycle_counter <= mcycle_counter + 1;
        end
    end

`ifndef SYNTHESIS
    assign pc_out = pc_current;
    assign inst_out = inst;
`endif


    wire pc_update_en = (current_state == STATE_EXECUTE) && lsu_done && ifu_valid; 
    ysyx_25040109_IFU ifu(
        .clk(clk),
        .rst(rst),
        .next_pc(next_pc),
        .pc_update_en(pc_update_en),
        .pc_current(pc_current),
        .inst_out(inst),
        .ifu_valid(ifu_valid),
        .ifu_raddr(ifu_raddr),
        .ifu_rdata(ifu_rdata)
    );



    always @(posedge clk) begin
        if (rst) begin
            current_state <= STATE_FETCH_INST;
        end else begin
            current_state <= next_state;
        end
    end

    assign next_state = (current_state == STATE_FETCH_INST) ? STATE_EXECUTE : STATE_FETCH_INST;




    // IDU 模块
    ysyx_25040109_IDU idu (
        .inst(inst),
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


                        
    ysyx_25040109_LSU lsu (
            .clk(clk),
            .rst(rst),
            .is_load(is_load),
            .is_store(is_store),
            .alu_result(alu_result),
            .rs2_data(rs2_data),
            .funct3(funct3),
            .lsu_start(lsu_start),
            .load_data(load_data),
            .lsu_done(lsu_done),
            .lsu_addr(lsu_addr),
            .lsu_wen(lsu_wen),
            .lsu_wdata(lsu_wdata),
            .lsu_wmask(lsu_wmask),
            .lsu_rdata(lsu_rdata)
        );           

    // 内存接口



    assign writeback_data =is_csrrw ? csr_rdata :
                            is_load ? load_data : alu_result;


    wire [4:0] raddr1 = inst[19:15];
    wire [4:0] raddr2 = inst[24:20];                        

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
