; gpu_demo.asm
; Example GPU program source.

%include "../include/common.inc"

section .data
    demo_kernel:
        dq GPU_ENCODE_OP(OP_VADD, 0, 1)
        dq GPU_ENCODE_OP(OP_HALT, 0, 0)

; The runnable GPU scaffold in `gpu_1024.asm` uses the same opcode shape.
