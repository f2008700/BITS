module Main_Ctrl_Unit(Opcode_6b, Signals_9b);
	output reg [8:0] Signals_9b;
	input [5:0] Opcode_6b;
	parameter s0=6'b000000,s1=6'b001000,s2=6'b100011,s3=6'b101011,s4=6'b000100;
	
	always @(Opcode_6b)
		case (Opcode_6b)
			s0:	Signals_9b=9'b110000010;
			s1:	Signals_9b=9'b011000000;
			s2:	Signals_9b=9'b011010100;
			s3:	Signals_9b=9'b001001000;
			s4:	Signals_9b=9'b000100001;
		endcase	
endmodule

module ALU_Ctrl_Unit (funct_6b, ALUOp_2b, ALU_Ctrl_Out_4b);
	output reg [3:0] ALU_Ctrl_Out_4b;
	input [5:0] funct_6b;
	input [1:0] ALUOp_2b;
	parameter s0=6'b100000,s1=6'b100010,s2=6'b100100,s3=6'b100101;
	
	always @(ALUOp_2b or funct_6b)
		begin	
			if(ALUOp_2b==2'b00)
				ALU_Ctrl_Out_4b=4'b0010;
			else if(ALUOp_2b==2'b01)
				ALU_Ctrl_Out_4b=4'b0110;
			else if(ALUOp_2b==2'b10)
				begin 
					case(funct_6b)
						s0:	ALU_Ctrl_Out_4b=4'b0010;
						s1:	ALU_Ctrl_Out_4b=4'b0110;
						s2:	ALU_Ctrl_Out_4b=4'b0000;		
						s3:	ALU_Ctrl_Out_4b=4'b0001;
					endcase
				end
		/*	else // For bit combination 11 then also performing the same operation
				begin 
					case(funct_6b)
						s0:	ALU_Ctrl_Out_4b=4'b0010;
						s1:	ALU_Ctrl_Out_4b=4'b0110;
						s2:	ALU_Ctrl_Out_4b=4'b0000;		
						s3:	ALU_Ctrl_Out_4b=4'b0001;
					endcase
				end
		*/
		end
endmodule	

module Adder (PC_32b, SExtnShft_32b, BrAdd_32b);
	output reg [31:0] BrAdd_32b;
	input [31:0] SExtnShft_32b;
	input [31:0] PC_32b;
	
	always @ (PC_32b or SExtnShft_32b)
		BrAdd_32b=PC_32b+SExtnShft_32b;
endmodule

module Mux (BusB_32b, SExtn_32, ALUSrc2_32b, ALUSrc_1b);
	output reg [31:0] ALUSrc2_32b;
	input [31:0] BusB_32b;
	input [31:0] SExtn_32;
	input ALUSrc_1b;
	
	always @(BusB_32b or SExtn_32 or ALUSrc_1b)
		case (ALUSrc_1b)
			1'b0: ALUSrc2_32b=BusB_32b;
			1'b1: ALUSrc2_32b=SExtn_32;
		endcase
endmodule

module ALU (BusA_32b,ALUSrc2_32b,ALU_Ctrl_Out_4b,ALUOut_32b,Zero_1b);
	output reg [31:0] ALUOut_32b;
	output reg [1:0] Zero_1b;
	input [31:0] BusA_32b;
	input [31:0] ALUSrc2_32b;
	input [3:0] ALU_Ctrl_Out_4b;
		
	always @(BusA_32b or ALUSrc2_32b or ALU_Ctrl_Out_4b)
		case(ALU_Ctrl_Out_4b)
			4'b0010:	ALUOut_32b=(BusA_32b)+(ALUSrc2_32b);
			4'b0110: ALUOut_32b=(BusA_32b)-(ALUSrc2_32b);
			4'b0000:	ALUOut_32b=(BusA_32b)&(ALUSrc2_32b);	
			4'b0001: ALUOut_32b=(BusA_32b)|(ALUSrc2_32b);
		endcase
	always @(ALUOut_32b)
		begin
			if(ALUOut_32b==32'b00000000000000000000000000000000)
				Zero_1b=1'b1;
			else	
				Zero_1b=1'b0;
		end
endmodule

module Execution_Ctrl_Unit (Opcode_6b, PC_32b, BusA_32b, BusB_32b,
Imm_16b, Signals_9b, BrAdd_32b, Zero_1b, ALUOut_32b);
	output  [8:0]	Signals_9b;
	output  [31:0] BrAdd_32b;
	output  Zero_1b;
	output  [31:0] ALUOut_32b;
	input [5:0] Opcode_6b;
	input [31:0] PC_32b;
	input [31:0] BusA_32b;
	input [31:0] BusB_32b;
	input [15:0] Imm_16b;
	wire [31:0] SExtn_32;
	wire [31:0] SExtnShft_32b;
	wire [31:0] ALUSrc2_32b;
	wire [3:0] ALU_Ctrl_Out_4b;
	
	Main_Ctrl_Unit MCU(Opcode_6b, Signals_9b);	

	assign SExtn_32=(Imm_16b[15])?{16'b1111111111111111,Imm_16b}:{16'b0000000000000000,Imm_16b};
	
	assign SExtnShft_32b=SExtn_32<<2;
	
	Adder A1(PC_32b, SExtnShft_32b, BrAdd_32b);
	Mux M1(BusB_32b, SExtn_32, ALUSrc2_32b, Signals_9b[6]);
	ALU_Ctrl_Unit ACU(Imm_16b[5:0], Signals_9b[1:0], ALU_Ctrl_Out_4b);
	ALU AL(BusA_32b,ALUSrc2_32b,ALU_Ctrl_Out_4b,ALUOut_32b,Zero_1b);	
endmodule

module t_Execution_Ctrl_Unit;	
	
	wire  [8:0]	Signals_9b;
	wire  [31:0] BrAdd_32b;
	wire  Zero_1b;
	wire  [31:0] ALUOut_32b;
	reg [5:0] Opcode_6b;
	reg [31:0] PC_32b;
	reg [31:0] BusA_32b;
	reg [31:0] BusB_32b;
	reg [15:0] Imm_16b;
	
	Execution_Ctrl_Unit ECU(Opcode_6b, PC_32b, BusA_32b, BusB_32b,
Imm_16b, Signals_9b, BrAdd_32b, Zero_1b, ALUOut_32b);
	
	initial #200 $finish; 
		
	
	initial begin
		Opcode_6b=6'b000000; 
		PC_32b=32'b00000000000000000000000000000011;
		BusA_32b=32'b00000000000000000000000000000100;
		BusB_32b=32'b00000000000000000000000000000011;
		Imm_16b=16'b0000000000100000;
	
	#10 Opcode_6b=6'b000000; 
		PC_32b=32'b00000000000000000000000000000011;
		BusA_32b=32'b00000000000000000000000000000100;
		BusB_32b=32'b00000000000000000000000000000011;
		Imm_16b=16'b0000000000100010;
		
	#10 Opcode_6b=6'b000000; 
		PC_32b=32'b00000000000000000000000000000011;
		BusA_32b=32'b00000000000000000000000000000011;
		BusB_32b=32'b00000000000000000000000000000011;
		Imm_16b=16'b0000000000100010;
	
	end
endmodule

