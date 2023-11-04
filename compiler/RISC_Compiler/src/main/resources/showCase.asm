; This file will just contain some functions
; to show, what is possible with my assembly language

use system.asm       ; This will allow to use routines from another asm file

_start:                  ; This will be the starting routine
    ADDI x5, zero, #06   ; Write the value F2 into register x5
    ADDI x6, zero, #01   ; Write "           "
    JMP _loop            ; Jump to routine loop

_loop:
    BEQ x5, x6, 00       ; Check if x5 = x6
    JMP _exit            ; if so exit the loop
    ADDI x6, x6, #01     ; otherwise go through loop again
    JMP _loop

_exit:
    NOP                 ; kinda stop operation...