; cpu decode module

%include "../../../include/common.inc"
%include "../../cpu/opcodes.inc"

global cpu_decode_fields

; in: rax = raw opcode
; out: rax = op, rcx = dst, rdx = src, r8 = imm
cpu_decode_fields:
    mov r9, rax

    mov eax, r9d
    and eax, 0xFF

    mov ecx, r9d
    shr ecx, 8
    and ecx, 0xFF

    mov edx, r9d
    shr edx, 16
    and edx, 0xFF

    mov r8, r9
    shr r8, 24
    ret
