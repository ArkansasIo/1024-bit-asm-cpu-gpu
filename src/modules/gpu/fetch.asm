; gpu fetch module

%include "../../../include/common.inc"
%include "../../gpu/opcodes.inc"

global gpu_fetch_opcode

; in: rdi = memory base, rsi = pc
; out: rax = opcode
gpu_fetch_opcode:
    mov rax, [rdi + rsi*8]
    ret
