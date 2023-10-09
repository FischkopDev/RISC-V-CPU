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
</ul>

<h2>Instruction Set</h2>
A short description of whats the binary/hex equivalent to a given assembly instruction.
<br>ALU/arithmetic instructions have code between 000 0001 and 0000 1111.

        OP-Code         |    Assembly-Code      |       Atributes       |       Description
        ---------------------------------------------------------------------------------------------------------
        0000 0000       |       NOP             |                       | Execute no operation
        0000 0001       |       ADD             | <Ret-Reg><Reg1><Reg2> | Add two values of given register
        0000 0010       |       ADDI            | <Ret-Reg><Reg1><VALUE>| Add imidiate values onto register
        0000 0011       |       SUB             | <Ret-Reg><Reg1><Reg2> | Subtract two register
        0000 0100       |       SUBI            |                       |
        0000 0101       |	MULT		|			|
	0000 0110	|	MULTI		|			|
	0000 0111	|	DIV		|			|
	0000 1000	|	DIVI		|			|
	0000 1001	|			|			|
	0000 1010	|			|			|
	0000 1011	|			|			|
	0000 1100	|			|			|
	0000 1101	|			|			|
	0000 1110	|			|			|
	0000 1111	|			|			|
	0001 0000	|	JMP		| <Pos-Arg1><Pos-Arg2>	| jump to an address with 16Bit!
	0001 0001	|	BEQ		| <Reg-Arg1><Reg-Arg2>	| Check if two register are equals
	0001 0010	|	BNEQ		| <Reg-Arg1><Reg-Arg2>	| Check if two register aren't equals
	0001 0011	|			|			|

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
