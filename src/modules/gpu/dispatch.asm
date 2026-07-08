; gpu dispatch module

%include "../../../include/common.inc"
%include "../../../include/structs.inc"
%include "../../gpu/opcodes.inc"

extern gpu_copy_1024_ptr
extern gpu_add_1024_ptr

global gpu_dispatch_step

; in:
;   rdi = gpu_state base
;   rsi = control memory base
; out:
;   rax = new pc
;   rdx = halt flag
gpu_dispatch_step:
    push rbx
    push r12
    push r13
    push r14
    push r15

    mov rbx, rdi
    mov r12, rsi

    mov rax, [rbx + gpu_state.pc]
    mov r10, [r12 + rax*8]

    mov ecx, r10d
    and ecx, 0xFF
    cmp ecx, OP_HALT
    je .halt

    mov ecx, r10d
    shr ecx, 8
    and ecx, 0xFF
    mov edx, r10d
    shr edx, 16
    and edx, 0xFF

    lea r11, [rbx + gpu_state.vregfile]
    mov r12, rcx
    shl r12, 7
    lea r13, [r11 + r12]
    mov r14, rdx
    shl r14, 7
    lea r15, [r11 + r14]

    cmp r10b, OP_VCOPY
    je .vcopy
    cmp r10b, OP_VADD
    je .vadd
    jmp .next

.vcopy:
    mov rdi, r13
    mov rsi, r15
    call gpu_copy_1024_ptr
    jmp .next

.vadd:
    mov rdi, r13
    mov rsi, r15
    call gpu_add_1024_ptr
    jmp .next

.next:
    inc rax
    mov [rbx + gpu_state.pc], rax
    xor edx, edx
    pop r15
    pop r14
    pop r13
    pop r12
    pop rbx
    ret

.halt:
    xor edx, edx
    inc edx
    pop r15
    pop r14
    pop r13
    pop r12
    pop rbx
    ret
