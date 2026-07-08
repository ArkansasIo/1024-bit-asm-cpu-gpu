; cpu execute module

%include "../../../include/common.inc"
%include "../../../include/structs.inc"
%include "../../cpu/opcodes.inc"

extern cpu_zero_1024_ptr
extern cpu_copy_1024_ptr
extern cpu_add_1024_ptr
extern cpu_sub_1024_ptr
extern cpu_eq_1024_ptr
extern cpu_load_imm64_ptr

global cpu_execute_step

; in:
;   rdi = state base (cpu_state)
;   rsi = memory base
; out:
;   rax = new pc
;   rdx = halt flag (0/1)
cpu_execute_step:
    push rbx
    push r12
    push r13
    push r14
    push r15

    mov rbx, rdi
    mov r12, rsi

    mov rax, [rbx + cpu_state.pc]
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

    mov r8, r10
    shr r8, 24

    lea r11, [rbx + cpu_state.regfile]
    mov r12, rcx
    shl r12, 7
    lea r13, [r11 + r12]
    mov r14, rdx
    shl r14, 7
    lea r15, [r11 + r14]

    cmp r10b, OP_MOV_IMM
    je .mov_imm
    cmp r10b, OP_ADD
    je .add
    cmp r10b, OP_SUB
    je .sub
    cmp r10b, OP_BEQ
    je .beq
    jmp .next

.mov_imm:
    mov rdi, r13
    mov rsi, r8
    call cpu_load_imm64_ptr
    jmp .next

.add:
    mov rdi, r13
    mov rsi, r15
    call cpu_add_1024_ptr
    jmp .next

.sub:
    mov rdi, r13
    mov rsi, r15
    call cpu_sub_1024_ptr
    jmp .next

.beq:
    mov rdi, r13
    mov rsi, r15
    call cpu_eq_1024_ptr
    test eax, eax
    jz .next
    mov rax, [rbx + cpu_state.pc]
    inc rax
    mov rax, [r12 + rax*8]
    mov [rbx + cpu_state.pc], rax
    xor edx, edx
    pop r15
    pop r14
    pop r13
    pop r12
    pop rbx
    ret

.next:
    inc rax
    mov [rbx + cpu_state.pc], rax
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
