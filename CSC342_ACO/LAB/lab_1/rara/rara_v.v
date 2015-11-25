`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:45:31 01/19/2012 
// Design Name: 
// Module Name:    rara_v 
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
module rara_v(A,B,C,reset,sum,ca);
input A,B,C,reset;
output sum,ca;
reg sum,ca;

always @(A or B or C or reset)
//begin 
	if (reset == 1)
		begin
			sum = 0;
			ca = 0;
		end
	else
		begin
			sum = ( (~A&~B&C)| (~A&B&~C) | (A&~B&~C) | (A&B&C) );
			ca = ( (A&C) | (A&B) | (B&C) );
		end
//end
endmodule

module t_rara;
reg a,b,c,res;
wire su,car;
parameter stop = 30;

rara_v(a,b,c,res,su,car);

initial #stop $finish;

initial
	begin
			a=0;b=0;c=0;res=0;
	#5		a=1;
	#5		res=1;
	#5		res=0;b=1;
	#5		c=1;
	#5		b=0;a=0;
	#5		res=1;
	end
	
initial
	begin
		$display("time	A	B	C	=	carry	sum");
		$monitor("%0d	%b	%b	%b	=	%b		%b",$time,a,b,c,car,su);
	end

endmodule 