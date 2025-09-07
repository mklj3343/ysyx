module  top(
    input clk,clrk,nextdate_n,ps2_clk,ps2_date,
    output reg [7:0] date,
    output reg ready,
    output reg overflow,
    output reg [6:0] seg0,seg1,seg2,seg3,seg4,seg5
);

reg [9:0] buffer;
reg [7:0] fifo;
reg [3:0] w_ptr,r_ptr;
reg [3:0] count;
reg [2:0] ps2_clk_sync;
reg [9:0] last_buffer;
reg [7:0] button_times;
reg release_detected;


initial begin
   // $monitor("ascll=%x,three=%x,four=%x,date=%x",ascll,three,four,date);
    button_times=8'b0;
    release_detected=1'b1;
end 


always @(posedge clk)begin
    ps2_clk_sync<={ps2_clk_sync[1:0],ps2_clk};

end

wire sampling=ps2_clk_sync[2] & ~ps2_clk_sync[1];

always @(posedge clk)begin
    if(clrk)begin
        count<=4'd0;w_ptr<=4'd0;r_ptr<=4'd0;
        ready<=1'b0;overflow<=1'b0;release_detected<=1'b0;
    end else begin
        if(ready)begin
            if(nextdate_n==1'b0)begin
                r_ptr<=r_ptr+1'b1;
               $display("date %x", date[7:0]);
                if(w_ptr==r_ptr+1'b1)begin
                    ready<=1'b0;
                end
            end
        end


        if(sampling)begin
            if(count==4'd10)begin
                if(buffer[0]==0 && ps2_date && (^buffer[9:1]) )begin
                 if (buffer[8:1] != 8'hF0 && last_buffer[8:1]!= 8'hF0) begin
                    fifo <= buffer[8:1]; 
                    last_buffer<=buffer;
                    w_ptr<=w_ptr+1'b1;
                    ready<=1'b1;
                    overflow<=overflow | (r_ptr==w_ptr+1'b1);
                    release_detected <= 1'b0; 
                     button_times <=(last_buffer!=buffer) ? button_times + 1'b1 :button_times;
                 end   
                
                    $display("buffer %x", buffer[8:1]);
                    $display("ascll %d,three=%d,four=%d",ascll,three,four);


                    if (buffer[8:1] == 8'hF0) begin
                        release_detected <= 1'b1;
                    end 
                    last_buffer <= buffer; 
                
                end
                count<=4'b0;

            end  else begin
                w_ptr<=w_ptr;
                r_ptr<=r_ptr;
                buffer[count]<=ps2_date;
                count<=count+1'b1;
                
            end

        end
        end

    end
        assign date=fifo;

wire [3:0] one,two;
assign one=date[3:0];
assign two=date[7:4];

sevens_light_low first(.num(one),.ready(release_detected),.seg(seg0));
sevens_light_low second(.num(two),.ready(release_detected),.seg(seg1));

wire [7:0] ascll;
wire [7:0] three,four;

key_to_ascii change(.key(date),.ascii(ascll));

assign three=ascll % 10;
assign four=ascll /10;


sevens_light_second third(.num(three),.ready(release_detected),.seg(seg2));
sevens_light_second fourth(.num(four),.ready(release_detected),.seg(seg3));


wire [7:0] five,six;
assign five=button_times % 10;
assign six=button_times / 10;

sevens_light_high fifth(.num(five),.seg(seg4));
sevens_light_high sixth(.num(six),.seg(seg5));






endmodule 






module sevens_light_low(
    input [3:0] num,
    input  ready,
    output reg [6:0] seg
);

    always @(*) begin
        if(ready==1'd0)begin
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
            4'd11: seg = 7'b1100000; //B显示为b
            4'd12: seg = 7'b0110001;  
            4'd13: seg = 7'b1000010;  
            4'd14: seg = 7'b0110000;  
            4'd15: seg = 7'b0111000; 
            default: seg = 7'b0000000; 
        endcase
        end else begin
            seg = 7'b1111111; 
        end
    end

endmodule


module sevens_light_high(
    input [7:0] num,
    output reg [6:0] seg
);

    always @(*) begin
      
        case(num)
        8'd0: seg = 7'b0000001; 
        8'd1:seg=7'b1001111;
        8'd2:seg=7'b0010010;
        8'd3:seg=7'b0000110;
        8'd4:seg=7'b1001100;
        8'd5:seg=7'b0100100;
        8'd6:seg=7'b1100000;
        8'd7:seg=7'b0001111; 
        8'd8: seg = 7'b0000000; 
        8'd9: seg = 7'b0001100; 
        default: seg=7'b1111111;
        endcase
   
    end

endmodule
module key_to_ascii (
    input [7:0] key,
    output reg [7:0] ascii
);

always @(*) begin
    case (key)
        8'h1C: ascii = 8'd65;
        8'h32: ascii = 8'd66;
        8'h21: ascii = 8'd67;
        8'h23: ascii = 8'd68;
        8'h24: ascii = 8'd69;
        8'h2B: ascii = 8'd70;
        8'h34: ascii = 8'd71;
        8'h33: ascii = 8'd72;
        8'h43: ascii = 8'd73;
        8'h3B: ascii = 8'd74;
        8'h42: ascii = 8'd75;
        8'h4B: ascii = 8'd76;
        8'h3A: ascii = 8'd77;
        8'h31: ascii = 8'd78;
        8'h44: ascii = 8'd79;
        8'h4D: ascii = 8'd80;
        8'h15: ascii = 8'd81;
        8'h2D: ascii = 8'd82;
        8'h1B: ascii = 8'd83;
        8'h2C: ascii = 8'd84;
        8'h3C: ascii = 8'd85;
        8'h2A: ascii = 8'd86;
        8'h1D: ascii = 8'd87;
        8'h22: ascii = 8'd88;
        8'h35: ascii = 8'd89;
        8'h1A: ascii = 8'd90;
        8'h45: ascii = 8'd48;
        8'h16: ascii = 8'd49;
        8'h1E: ascii = 8'd50;
        8'h26: ascii = 8'd51;
        8'h25: ascii = 8'd52;
        8'h2E: ascii = 8'd53;
        8'h36: ascii = 8'd54;
        8'h3D: ascii = 8'd55;
        8'h3E: ascii = 8'd56;
        8'h46: ascii = 8'd57;
        default: ascii = 8'd0;
    endcase
end

endmodule


module sevens_light_second(
    input [7:0] num,
    input  ready,
    output reg [6:0] seg
);

    always @(*) begin
        if(ready==1'd0)begin
        case(num)
        8'd0: seg = 7'b0000001; 
        8'd1:seg=7'b1001111;
        8'd2:seg=7'b0010010;
        8'd3:seg=7'b0000110;
        8'd4:seg=7'b1001100;
        8'd5:seg=7'b0100100;
        8'd6:seg=7'b1100000;
        8'd7:seg=7'b0001111; 
            8'd8: seg = 7'b0000000; 
            8'd9: seg = 7'b0001100; 
            default: seg = 7'b0000000; 
        endcase
        end else begin
            seg = 7'b1111111; 
        end
    end

endmodule


