module ysyx_25040109_LSU (
    input clk,
    input rst,
    input is_load,
    input is_store,
    input [31:0] alu_result, 
    input [31:0] rs2_data,   
    input [2:0] funct3,
    input lsu_start,          

    output reg [31:0] load_data, 
    output reg lsu_done,      
    output reg [31:0] lsu_addr,
    output reg lsu_wen,
    output reg [31:0] lsu_wdata,
    output reg [3:0] lsu_wmask,
    input [31:0] lsu_rdata
);

    localparam  STATE_IDLE = 1'b0 ;
    localparam  STATE_WAIT = 1'b1;

    reg current_state ;


    always @(posedge clk) begin
        if(rst)begin
            current_state <= STATE_IDLE;
        end else begin
            case (current_state)
            STATE_IDLE: if(lsu_start) current_state <= STATE_WAIT;
            STATE_WAIT: current_state <= STATE_IDLE;
            endcase
        end
    end


    always @(posedge clk) begin
        if(!rst && current_state == STATE_IDLE && lsu_start)begin
            lsu_addr <= alu_result;
            lsu_wen  <= is_store;
            lsu_wdata <= rs2_data;

            case (funct3)
            3'b000: lsu_wmask <= 4'b0001 << alu_result[1:0];
            3'b010: lsu_wmask <= 4'b1111;
            default:lsu_wmask <= 4'b0000; 
            endcase
        end
    end

    always @(*) begin
        lsu_done = (current_state ==  STATE_WAIT) || (is_store && current_state == STATE_IDLE);
        if(is_load && current_state == STATE_WAIT)begin
            case(funct3)
            3'b010: load_data = lsu_rdata;
            3'b100: load_data = {24'b0,lsu_rdata[7:0]};
            default: load_data = 32'h0;
            endcase
        end else begin
            load_data = 32'b0;
        end
    end





endmodule
