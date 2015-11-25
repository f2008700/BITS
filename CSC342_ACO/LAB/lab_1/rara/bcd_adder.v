`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:23:23 01/19/2012 
// Design Name: 
// Module Name:    bcd_adder 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module bcd_adder(A,B,C,reset,sum,carry);

input [3:0] A;
input [3:0] B;
input C;
input reset;
output [3:0] sum;
output carry;

wire [3:0] A;
wire [3:0] B;
wire C;
wire reset;
wire [3:0] sum;
wire carry;

wire [3:0] T;
wire c1,c2,c3,co;
wire l1,l2,l3,l4;
adder a1(.A (A),.B (B),.C (C),.reset (reset),.sum (T),.carry (co) );

assign l1 = co | (T[1] & T[3]) | (T[3] & T[2]); 
assign carry = l1;
assign sum[0] = T[0];
assign l2 = T[1];
assign l3 = T[2];
assign l4 = T[3];

rara_v r1(.A (l2),.B (l1),.C (0),.reset (reset),.sum (sum[1]),.ca (c1) );
rara_v r2(.A (l3),.B (l1),.C (c1),.reset (reset),.sum (sum[2]),.ca (c2) );
rara_v r3(.A (l4),.B (0),.C (c2),.reset (reset),.sum (sum[3]),.ca (c3));
endmodule

module t_bcd;
reg [3:0] t_A;
reg [3:0] t_B;
reg t_C;
reg t_reset;
wire [3:0] t_sum;
wire t_carry;

parameter stop = 75;

bcd_adder(t_A,t_B,t_C,t_reset,t_sum,t_carry);
 
initial #stop $finish;

initial 
begin 
	t_A=4'b0000;t_B=4'b0000;t_reset = 1;t_C=0;
	#5 t_reset = 0; t_A =4'b0011;

repeat (7)	
	begin
	#5 t_A = t_A + 4'b0001; 
	end
repeat (7)	
	begin
	#5 t_B = t_B + 4'b0001; 
	end
end

initial 
begin 
$monitor("%0d	%b	%b	%b	%b	%b	%b",$time,t_A,t_B,t_C,t_reset,t_sum,t_carry);
end

endmodule
