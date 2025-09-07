module top(
    input  clk,
    input [2:0] select,
    input [3:0] a,b,
    output reg [3:0] result,
    output reg zero,
    output reg cin,
    output reg overflow,
    output reg compare_out,
    output reg [6:0] seg0,seg1
);


ALU test(.clk(clk),.select(select),.a(a),.b(b),.result(result),.zero(zero),.cin(cin),.overflow(overflow),.compare_out(compare_out),.seg0(seg0),.seg1(seg1));    

always @(result) begin
    $display("a=%d, b=%d ,result=%d,zero=%d,cin=%d,overflow=%d,compare_out=%d,",a,b,result,zero,cin,overflow,compare_out);
end

//成功实现功能，但数码管我只设置了0~13
//引脚对应select (BTNL,BTNC,BTNR) ，zero LD0，compare_out LD1，cin LD2，overflow LD3 

endmodule