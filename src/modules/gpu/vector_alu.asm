; gpu vector ALU module

%include "../../../include/common.inc"
%include "../../../include/structs.inc"

global gpu_zero_1024_ptr
global gpu_copy_1024_ptr
global gpu_add_1024_ptr

gpu_zero_1024_ptr:
    mov rcx, LIMBS_1024
.zero_loop:
    mov qword [rdi], 0
    add rdi, 8
    dec rcx
    jnz .zero_loop
    ret

gpu_copy_1024_ptr:
    mov rcx, LIMBS_1024
.copy_loop:
    mov rax, [rsi]
    mov [rdi], rax
    add rsi, 8
    add rdi, 8
    dec rcx
    jnz .copy_loop
    ret

gpu_add_1024_ptr:
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
