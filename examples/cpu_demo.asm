; cpu_demo.asm
; Example CPU program source.

%include "../include/common.inc"

section .data
    demo_program:
        dq CPU_ENCODE_OP(OP_MOV_IMM, 0, 0, 1)
        dq CPU_ENCODE_OP(OP_MOV_IMM, 1, 0, 2)
        dq CPU_ENCODE_OP(OP_ADD, 0, 1, 0)
        dq CPU_ENCODE_OP(OP_HALT, 0, 0, 0)

; This file is intentionally small: it demonstrates the opcode encoding
; used by the CPU scaffold rather than duplicating the full emulator.
