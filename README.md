<h1>32-Bit CPU</h1>
This project will simulate a running cpu with RISC-V architecture.
It will also contain a custom assembly language and probably a compiler for C language.

<h2>General</h2>
This cpu has a 32Bit architecture. For this reason all instructions will be seperated into.<br>
Instruction(8Bit) + Return-Register(8Bit) + Atribute 1(8Bit) + Atribute 2(8Bit)

<h2>Setup</h2>

<h2>Dependencies</h2>
<ul>
<li>Logisim version 2.16.1.4</li>
<li>CMake 3.0</li>
</ul>

<h2>Instruction Set</h2>
A short description of whats the binary/hex equivalent to a given assembly instruction.
<br>ALU/arithmetic instructions have code between 000 0001 and 0000 1111.

    OP-Code(BIN/Hex)|    Assembly-Code      |       Atributes       |       Description
    ---------------------------------------------------------------------------------------------------------
    0000 0000 (00)  |       NOP             |                       | Execute no operation
    0000 0001 (01)  |       ADD             | <Ret-Reg><Reg1><Reg2> | Add two values of given register
    0000 0010 (02)  |       ADDI            | <Ret-Reg><Reg1><VALUE>| Add imidiate values onto register
    0000 0011 (03)  |       SUB             | <Ret-Reg><Reg1><Reg2> | Subtract two register
    0000 0100 (04)  |       SUBI            |                       |
    0000 0101 (05)  |		MULT			|						|
	0000 0110 (06)  |		MULTI			|						|
	0000 0111 (07)  |		DIV				|						|
	0000 1000 (08)  |		DIVI			|						|
	0000 1001 (09)	|						|						|
	0000 1010 (0A)	|						|						|
	0000 1011 (0B)	|						|						|
	0000 1100 (0C)	|						|						|
	0000 1101 (0D)	|						|						|
	0000 1110 (0E)	|						|						|
	0000 1111 (0F)	|						|						|
	0001 0000 (10)	|		JMP				| <Pos-Arg1><Pos-Arg2>	| jump to an address with 16Bit!
	0001 0001 (11)	|		BEQ				| <Reg-Arg1><Reg-Arg2>	| Check if two register are equals
	0001 0010 (12)	|		BNEQ			| <Reg-Arg1><Reg-Arg2>	| Check if two register aren't equals
	0001 0011 (13)	|		PRNT			| <Reg-Arg1>			| Print something on display
	0001 0100 (14)  |	 	RST				|		   --			| Reset display
	0001 0101 (15)  | 		

<h2>Register Design</h2>

	Register	|	Alias		|	Description
	---------------------------------------------------------------------------------------------------------
		x0	|	zero		| Hard wired zero register
		x1	|	ra		| Return address
		x2	|	sp		| Stackpointer
		x3	|	gp		| global pointer
		x4	|	tp		| Thread pointer
		x5-7	|	t0-2		| Temporary register
		x8-9	|	s0-1		| Saved register
		x10-11	|	a0-1		| Function arguments
		x12-15	|	s0-2		| Saved register	

<h2>Pipeline</h2>
The given pipeline has a depth of 2. 

<h2>Example Code</h2>
To run specific code you need to fill up the RAM with HEX values. One example to write 5 into register 1 would look like this.<br>
Instruction = 02 (ADDI), Return-Register = 01 (REG), First-Argument = 00 (ZERO), Second-Argument = 05 (HEX-VALUE of 5)<br>
The complete instruction will be:<br><br>

	02010005 00000000 ...

To run this in logisim you need to write HEX code like this into a file and load it up in logisim as RAM values.
