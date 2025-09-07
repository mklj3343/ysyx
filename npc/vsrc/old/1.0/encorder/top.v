module top(
    input clk,
    input en,
    input [7:0] D,
    output reg [6:0] seg,
    output sympol
);

reg [2:0] temp_num;
encorder moen(.clk(clk),.en(en),.D(D),.out(temp_num),.sympol(sympol));
  
seven_segment_display  light(.num(temp_num),.seg(seg));

endmodule

