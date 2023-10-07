<h1>32-Bit CPU</h1>
This project will simulate a running cpu with RISC-V architecture.
It will also contain a custom assembly language and probably a compiler for C language.

<h2>General</h2>
This cpu has a 32Bit architecture. For this reason all instructions will be seperated into.<br>
Instruction(8Bit) + Return-Register(8Bit) + Atribute 1(8Bit) + Atribute 2(8Bit)

<h2>Setup</h2>

<h2>Dependencies</h2>
<ul>
<li>Logisim version 2.16.4</li>
</ul>

<h2>Instruction Set</h2>
A short description of whats the binary/hex equivalent to a given assembly instruction.

        OP-Code         |    Assembly-Code      |       Atributes       |       Description
        ---------------------------------------------------------------------------------------------------------
        0000 0000       |       NOP             |                       |       Execute no operation
        0000 0001       |       ADD             | <Ret-Reg><Reg1><Reg2> |       Add two values of given register
        0000 0010       |       ADDI            | <Ret-Reg><Reg1><VALUE>|       Add imidiate values onto register
        0000 0011       |       SUB             | <Ret-Reg><Reg1><Reg2> |       Subtract two register
        0000 0100       |       SUBI            |                       |
        0000 0101       |	MULT		|			|
	0000 0110	|	MULTI		|			|
	0000 0111	|	DIV		|			|
	0000 1000	|	DIVI		|			|
	0000 1001	|			|			|
	0000 1010	|			|			|
	0000 1011	|			|			|


<h2>Register Design</h2>
