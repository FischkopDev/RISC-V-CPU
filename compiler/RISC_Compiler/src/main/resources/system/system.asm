; This file represents the basics of any operating systems
; running on this CPU. It provides needed routines and
; environments.
; Keep in mind to always set ra before calling routines!

_init:                          ; Initialize the system and set sp
    ADDI sp, zero, #FF          ; Set sp to max address
    ADD s0, zero, ra            ; Write ra to s0

_boot:                          ; Boot the system and console
    ADD ra, zero, s0            ; Write back s0 to ra
    ADDI t0, zero, ("M")        ; Write ASCI of M to t0
    ADDI t1, zero, ("i")        ; Write
    ADDI t2, zero, ("n")

    PRNT t0
    PRNT t1
    PRNT t2

    ADDI t0, zero, ("i")        ; Write ASCI of M to t0
    ADDI t1, zero, ("m")
    ADDI t2, zero, ("a")

    PRNT t0
    PRNT t1
    PRNT t2

    ADDI t0, zero, ("l")        ; Write ASCI of M to t0
    ADDI t1, zero, (" ")
    ADDI t2, zero, ("O")

    PRNT t0
    PRNT t1
    PRNT t2

    ADDI t0, zero, ("S")        ; Write ASCI of M to t0
    ADDI t1, zero, (" ")
    ADDI t2, zero, ("1")

    PRNT t0
    PRNT t1
    PRNT t2

    JMP ra                      ; return to entry point

_put:                           ; Store on stack


_push:                          ; Delete from stack
