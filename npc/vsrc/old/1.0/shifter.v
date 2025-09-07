//先按SW9 ,再通过SW0-8调初始值，然后关闭SW9，然后就可以进行随机数生成

module top (
    output reg [6:0] seg0,seg1,
    input  [7:0] num,
    input clk,
    input  reset,
    output reg led

);
    reg [7:0] temp_shift;
    reg random;

always @(*) begin
    led=reset;
end

    reg [25:0] count;


    always @(posedge clk or posedge reset) begin
        if(reset)begin
            temp_shift<=num;
            count<=26'd0;
        end else if(count>26'd500) begin
         random<=temp_shift[0]^temp_shift[2]^temp_shift[3]^temp_shift[4];
         temp_shift<={random,temp_shift[7:1]};
         count <= 26'd0;
        end  else begin
            count<=count+1'b1;
        end
    end

    wire   [3:0]segone;
    wire   [3:0]segten;
    
assign    segone=temp_shift[3:0];
assign    segten=temp_shift[7:4];

sevens_light one(.num(segone),.seg(seg0));
sevens_light two(.num(segten),.seg(seg1));    


endmodule



module sevens_light(
    input [3:0] num,
    output reg [6:0] seg
);

    always @(*) begin
        case(num)
        4'd0: seg = 7'b0000001; 
        4'd1:seg=7'b1001111;
        4'd2:seg=7'b0010010;
        4'd3:seg=7'b0000110;
        4'd4:seg=7'b1001100;
        4'd5:seg=7'b0100100;
        4'd6:seg=7'b1100000;
        4'd7:seg=7'b0001111; 
            4'd8: seg = 7'b0000000; 
            4'd9: seg = 7'b0001100; 
            4'd10: seg = 7'b0000001;  //A显示不出来,用
            4'd11: seg = 7'b0000000; //B显示为8
            4'd12: seg = 7'b0110001;  
            4'd13: seg = 7'b0011100;  
            4'd14: seg = 7'b0110000;  
            4'd15: seg = 7'b0111000; 
            default: seg = 7'b0000000; 
        endcase
    end

endmodule