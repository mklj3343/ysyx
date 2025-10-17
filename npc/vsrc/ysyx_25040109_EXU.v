// Execution Unit (EXU)
// 功能：执行指令
// - ALU运算
// - CSR操作
// - 分支判断和下一条PC计算
// - JAL/JALR/分支跳转
module ysyx_25040109_EXU (
    input [31:0] rs1_data,
    input [31:0] rs2_data,
    input [31:0] imm,
    
    input reg_write_in,    
    output reg_write_en_out, 

    input [4:0] rd_addr,   
    input  [4:0]  rs1_addr, 
    input [31:0] pc,
    input [6:0] opcode,
    input [2:0] funct3,
    input [6:0] funct7,    
    input inst_invalid,  
    output [31:0] alu_result,
    output [4:0] rd_addr_out,  
    output reg [31:0] next_pc,

    input [11:0] csr_addr,
    input [31:0] csr_rdata,
    input [31:0] mepc,
    input [31:0] mtvec,

    output reg csr_we_out,
    output reg [31:0] csr_wdata_out
);
   

    wire [31:0] alu_a, alu_b;
    reg [31:0] alu_out; 
    reg [63:0] mul_temp;

    // ALU输入选择
    ysyx_25040109_MuxKeyWithDefault #(3, 7, 32) alu_a_select( 
        .out(alu_a),
        .key(opcode),
        .default_out(rs1_data), 
        .lut({
            7'b0010111, pc,    // AUIPC     
            7'b0110111, 32'b0, // LUI     
            7'b1101111, pc     // JAL     
        })
    );

    ysyx_25040109_MuxKeyWithDefault #(4,7,32) alu_b_select(
        .out(alu_b),
        .key(opcode),
        .default_out(imm),
        .lut({
            7'b0110011,rs2_data, 
            7'b1100011,rs2_data, 
            7'b0000011,imm,
            7'b0100011,imm
        })
    );
   
    wire [4:0] shift_amount = (opcode == 7'b0010011 && (funct3 == 3'b001 || funct3 == 3'b101)) ?   imm[4:0] : rs2_data[4:0];

    always @(*) begin
        if(inst_invalid)begin
            alu_out = 32'b0;
        end else begin
            casez({opcode,funct3,funct7})
                // I型指令
                {7'b0010011, 3'b000, 7'b???????}: alu_out = alu_a + alu_b; // ADDI
                {7'b0010011, 3'b010, 7'b???????}: alu_out = ($signed(alu_a) < $signed(alu_b)) ? 32'h1 : 32'h0; // SLTI
                {7'b0010011, 3'b011, 7'b???????}: alu_out = (alu_a < alu_b) ? 32'h1 : 32'h0; // SLTIU
                {7'b0010011, 3'b100, 7'b???????}: alu_out = alu_a ^ alu_b; // XORI
                {7'b0010011, 3'b110, 7'b???????}: alu_out = alu_a | alu_b; // ORI
                {7'b0010011, 3'b111, 7'b???????}: alu_out = alu_a & alu_b; // ANDI
                {7'b0010011, 3'b001, 7'b0000000}: alu_out = alu_a << shift_amount; // SLLI
                {7'b0010011, 3'b101, 7'b0000000}: alu_out = alu_a >> shift_amount; // SRLI
                {7'b0010011, 3'b101, 7'b0100000}: alu_out = $signed(alu_a) >>> shift_amount; // SRAI
                
                // R型指令
                {7'b0110011, 3'b000, 7'b0000000}: alu_out = alu_a + alu_b; // ADD
                {7'b0110011, 3'b000, 7'b0100000}: alu_out = alu_a - alu_b; // SUB
                {7'b0110011, 3'b001, 7'b0000000}: alu_out = alu_a << shift_amount; // SLL
                {7'b0110011, 3'b010, 7'b0000000}: alu_out = ($signed(alu_a) < $signed(alu_b)) ? 32'h1 : 32'h0; // SLT
                {7'b0110011, 3'b011, 7'b0000000}: alu_out = (alu_a < alu_b) ? 32'h1 : 32'h0; // SLTU
                {7'b0110011, 3'b100, 7'b0000000}: alu_out = alu_a ^ alu_b; // XOR
                {7'b0110011, 3'b101, 7'b0000000}: alu_out = alu_a >> shift_amount; // SRL
                {7'b0110011, 3'b101, 7'b0100000}: alu_out = $signed(alu_a) >>> shift_amount; // SRA
                {7'b0110011, 3'b110, 7'b0000000}: alu_out = alu_a | alu_b; // OR
                {7'b0110011, 3'b111, 7'b0000000}: alu_out = alu_a & alu_b; // AND

                // M扩展指令
                {7'b0110011, 3'b000, 7'b0000001}: begin
                    mul_temp = $signed(alu_a) * $signed(alu_b);
                    alu_out = mul_temp[31:0]; // MUL
                end
                {7'b0110011, 3'b001, 7'b0000001}: begin
                    mul_temp = $signed(alu_a) * $signed(alu_b);
                    alu_out = mul_temp[63:32]; // MULH
                end
                {7'b0110011, 3'b100, 7'b0000001}: begin
                    if(alu_b == 32'h0)
                        alu_out = 32'hFFFFFFFF;// 除零返回全1
                    else if(alu_a == 32'h80000000 && alu_b == 32'hFFFFFFFF)
                       alu_out = 32'h80000000;
                    else  alu_out = $signed(alu_a) / $signed(alu_b);
                end
                {7'b0110011, 3'b101, 7'b0000001}: begin // DIVU
                    if (alu_b == 32'h0) 
                        alu_out = 32'hFFFFFFFF;  // 除零返回全1
                    else
                        alu_out = alu_a / alu_b;
                end
                {7'b0110011, 3'b110, 7'b0000001}: begin // REM
                    if (alu_b == 32'h0) 
                        alu_out = alu_a;  // 除零返回被除数
                    else if (alu_a == 32'h80000000 && alu_b == 32'hFFFFFFFF)
                        alu_out = 32'h0;  // 溢出情况余数为0
                    else
                        alu_out = $signed(alu_a) % $signed(alu_b);
                end
                {7'b0110011, 3'b111, 7'b0000001}: begin // REMU
                    if (alu_b == 32'h0) 
                        alu_out = alu_a;  // 除零返回被除数
                    else
                        alu_out = alu_a % alu_b;
                end
                
                // U/J型
                {7'b0110111, 3'b???, 7'b???????}: alu_out = alu_b; // LUI
                {7'b0010111, 3'b???, 7'b???????}: alu_out = alu_a + alu_b; // AUIPC

                // Load/Store地址计算
                {7'b0000011, 3'b000, 7'b???????}: alu_out = alu_a + alu_b; // LB 
                {7'b0000011, 3'b001, 7'b???????}: alu_out = alu_a + alu_b; // LH
                {7'b0000011, 3'b010, 7'b???????}: alu_out = alu_a + alu_b; // LW
                {7'b0000011, 3'b100, 7'b???????}: alu_out = alu_a + alu_b; // LBU 
                {7'b0000011, 3'b101, 7'b???????}: alu_out = alu_a + alu_b; // LHU 

                {7'b0100011, 3'b000, 7'b???????}: alu_out = alu_a + alu_b; // SB 
                {7'b0100011, 3'b001, 7'b???????}: alu_out = alu_a + alu_b; // SH 
                {7'b0100011, 3'b010, 7'b???????}: alu_out = alu_a + alu_b; // SW 

                default: alu_out = 32'b0;
            endcase
        end
    end

    // CSR操作
    always @(*) begin
        csr_we_out = 1'b0;
        csr_wdata_out = 32'h0;

        if(opcode == 7'b1110011 && !inst_invalid)begin
            case(funct3)
                3'b001:begin
                    csr_we_out = 1'b1;
                    csr_wdata_out = rs1_data;
                end
                3'b010:begin
                    csr_we_out = (rs1_addr != 5'b0);
                    csr_wdata_out = csr_rdata | rs1_data;
                end
                default: begin
                    csr_we_out = 1'b0;
                    csr_wdata_out = 32'b0;
                end
            endcase
        end
    end

    wire is_csr_op = (opcode == 7'b1110011);
    wire [31:0] jal_result      = pc + 4;
    wire [31:0] jal_target      = pc + imm;
    wire [31:0] jalr_target = (rs1_data + imm) & 32'hFFFFFFFE; // 低位清零
    wire [31:0] branch_target   = pc + imm;

    // 分支条件判断
    wire branch_taken = (opcode == 7'b1100011) && (
        (funct3 == 3'b000 && rs1_data == rs2_data) ||                     // BEQ
        (funct3 == 3'b001 && rs1_data != rs2_data) ||                     // BNE
        (funct3 == 3'b100 && $signed(rs1_data) < $signed(rs2_data)) ||    // BLT
        (funct3 == 3'b101 && $signed(rs1_data) >= $signed(rs2_data)) ||   // BGE
        (funct3 == 3'b110 && rs1_data < rs2_data) ||                      // BLTU
        (funct3 == 3'b111 && rs1_data >= rs2_data)                        // BGEU
    );

    wire [11:0] funct12 = csr_addr;
    wire is_ecall = is_csr_op && (funct3 == 3'b000) && (funct12 == 12'h000);
    wire is_mret  = is_csr_op && (funct3 == 3'b000) && (funct12 == 12'h302);

    always @(*) begin
        if (!inst_invalid) begin
            if (is_ecall) begin
                next_pc = mtvec; // ecall: 跳转到异常入口
            end else if (is_mret) begin
                next_pc = mepc;  // mret: 从异常返回
            end else if (opcode == 7'b1101111) begin
                next_pc = jal_target;
            end else if (opcode == 7'b1100111) begin
                next_pc = jalr_target;
            } else if (branch_taken) begin
                next_pc = branch_target;
            end else begin
                next_pc = pc + 4; 
            end
        end else begin
            next_pc = pc + 4;
            `ifndef SYNTHESIS
            $display("Invalid instruction at PC=0x%08x", pc);
            `endif
        end
    end

    assign alu_result = (is_csr_op) ? csr_rdata : (opcode == 7'b1101111 || opcode == 7'b1100111) ? jal_result : alu_out;
    assign rd_addr_out = rd_addr;
    assign reg_write_en_out = reg_write_in && !inst_invalid;

endmodule
