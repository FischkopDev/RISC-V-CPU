; This file will just contain some functions
; to show, what is possible with my assembly language

use system.asm       ; This will allow to use routines from another asm file

start:                  ; This will be the starting routine
    ADDI x5, zero, #6   ; Write the value F2 into register x5
    ADDI x6, zero, #1   ; Write "           "
    JMP loop            ; Jump to routine loop

loop:
    BEQ x5, x6          ; Check if x5 = x6
    JMP exit            ; if so exit the loop
    ADDI x6, x6, #1     ; otherwise go through loop again
    JMP loop

exit:
    NOP                 ; kinda stop operation...