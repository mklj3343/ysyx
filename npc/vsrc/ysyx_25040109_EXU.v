module ysyx_25040109_EXU (
    input  [31:0] pc,
    input  [31:0] rs1_data,
    input  [31:0] rs2_data,
    input  [31:0] imm,
    input         inst_invalid,
    input         is_add,
    input         is_lui,
    input         is_jalr,
    output [31:0] alu_result,
    output [31:0] next_pc
);
    

wire [31:0] alu_a = (is_lui) ? 32'h0 : rs1_data;
wire [31:0] alu_b = (is_add) ? rs2_data : imm;  

wire [31:0] alu_out = alu_a + alu_b;  


assign alu_result = (is_jalr) ? (pc + 4) : alu_out;


wire [31:0] jalr_target = alu_out & 32'hFFFFFFFE;  
assign next_pc = (inst_invalid) ? (pc + 4) : 
                 (is_jalr ? jalr_target : (pc + 4));

endmodule

