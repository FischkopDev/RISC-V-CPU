; This is an example program to run an infinity loop
; adding 1 to register one.

NOP
ADDI ra,ra,#1	;This actually adds an emidiate value to register one
JMP #0001	    ;This will jump to address 1 given as hex value
