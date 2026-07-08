; cpu fetch module

%include "../../../include/common.inc"
%include "../../../include/structs.inc"
%include "../../cpu/opcodes.inc"

global cpu_fetch_opcode

; in: rdi = memory base, rsi = pc
; out: rax = opcode qword
cpu_fetch_opcode:
    mov rax, [rdi + rsi*8]
    ret
