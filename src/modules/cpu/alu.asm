; cpu ALU module
; Pointer-based 1024-bit helpers.

%include "../../../include/common.inc"
%include "../../../include/structs.inc"

global cpu_zero_1024_ptr
global cpu_copy_1024_ptr
global cpu_add_1024_ptr
global cpu_sub_1024_ptr
global cpu_eq_1024_ptr
global cpu_load_imm64_ptr

cpu_zero_1024_ptr:
    mov rcx, LIMBS_1024
.zero_loop:
    mov qword [rdi], 0
    add rdi, 8
    dec rcx
    jnz .zero_loop
    ret

cpu_copy_1024_ptr:
    mov rcx, LIMBS_1024
.copy_loop:
    mov rax, [rsi]
    mov [rdi], rax
    add rsi, 8
    add rdi, 8
    dec rcx
    jnz .copy_loop
    ret

cpu_add_1024_ptr:
    clc
    mov rcx, LIMBS_1024
.add_loop:
    mov rax, [rdi]
    adc rax, [rsi]
    mov [rdi], rax
    add rdi, 8
    add rsi, 8
    dec rcx
    jnz .add_loop
    ret

cpu_sub_1024_ptr:
    clc
    mov rcx, LIMBS_1024
.sub_loop:
    mov rax, [rdi]
    sbb rax, [rsi]
    mov [rdi], rax
    add rdi, 8
    add rsi, 8
    dec rcx
    jnz .sub_loop
    ret

cpu_eq_1024_ptr:
    mov rcx, LIMBS_1024
    xor eax, eax
.eq_loop:
    mov r8, [rdi]
    cmp r8, [rsi]
    jne .not_eq
    add rdi, 8
    add rsi, 8
    dec rcx
    jnz .eq_loop
    mov eax, 1
.not_eq:
    ret

cpu_load_imm64_ptr:
    push rdi
    call cpu_zero_1024_ptr
    pop rdi
    mov [rdi], rsi
    ret
