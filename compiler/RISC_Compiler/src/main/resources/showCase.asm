; This file will just contain some functions
; to show, what is possible with my assembly language

use system.asm       ; This will allow to use routines from another asm file

_start:                  ; This will be the starting routine
    ADDI x1, zero, #06   ; Write the value F2 into register x5
    ADDI x2, zero, #01   ; Write "           "
    NOP                 ;test
    NOP                 ;test

_loop:
    BEQ 00, x1, x2       ; Check if x5 = x6
    NOP                 ;test
    JMP _exit            ; if so exit the loop
    ADDI x2, x2, #01     ; otherwise go through loop again
    JMP _loop               ; same
    NOP                   ; does weird stuff
    NOP                 ;dumb

_exit:
    NOP                 ; kinda stop operation...