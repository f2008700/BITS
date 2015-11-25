module D_FF(D_1b, Q_1b, Clk);
	output reg Q_1b;
	input Clk,D_1b;
	
	always @ (posedge Clk)
			Q_1b<=D_1b;
			
endmodule

module Counter(Clk, Reset_1b, CountOut_4b);
	output reg [3:0] CountOut_4b;
	input Clk, Reset_1b;

	always @ (Reset_1b)
		if(Reset_1b)
			CountOut_4b=4'b0001;
			
	assign n0=(~CountOut_4b[0]);
	assign n1=(~CountOut_4b[0]);
	assign n2=(~CountOut_4b[0]);
	assign n3=(~CountOut_4b[0]);
	
	assign a00=(n0&CountOut_4b[1]&n2&n3);
	assign a01=(n0&CountOut_4b[1]&CountOut_4b[2]&CountOut_4b[3]);
	assign a02=(n0&n1&CountOut_4b[2]&n3);
	assign a03=(a00|a01|a02);
	
	assign a10=(a10&n0&n1&n2);
	assign a11=(n0&n2&n3);
	assign a12=(CountOut_4b[0]&n1&n2&n3);
	assign a13=(a10|a11|a12);
	
	assign a20=(n0&CountOut_4b[2]&CountOut_4b[3]);
	assign a21=(CountOut_4b[0]&CountOut_4b[2]&n3);
	assign a22=(n0&CountOut_4b[1]&n2&CountOut_4b[3]);
	assign a23=(a20|a21|a22);
	
	assign a30=(n0&CountOut_4b[2]&n3);
	assign a31=(CountOut_4b[1]&CountOut_4b[3]);
	assign a32=(CountOut_4b[0]&n2);
	assign a33=(CountOut_4b[0]&n1);
	assign a34=(a30|a31|a32|a33);

	D_FF DFF_0(a03,CountOut_4b[0],Clk);
	D_FF DFF_1(a13,CountOut_4b[1],Clk);
	D_FF DFF_2(a23,CountOut_4b[2],Clk);
	D_FF DFF_3(a34,CountOut_4b[3],Clk);		
		
endmodule

module t_Counter;
	reg Clk, Reset_1b;
	wire [3:0] CountOut_4b;
	
	Counter C1(Clk, Reset_1b, CountOut_4b);
	
	initial #200 $finish;

	initial begin Clk=0; forever #5 Clk=~Clk; end
	
	initial begin
	#0	Reset_1b=1'b0;
	#20	Reset_1b=1'b1;
		
	end
endmodule
	
