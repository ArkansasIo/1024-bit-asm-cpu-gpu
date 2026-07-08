; cpu_1024.asm
; 1024-bit CPU emulator scaffold (NASM / x86-64 Linux-style syscall ABI)
;
; A 1024-bit register is represented as 16 qwords.
;
; Current CPU opcodes:
;   0xFF HALT
;   0x01 MOV_IMM
;   0x02 ADD
;   0x03 SUB
;   0x04 BEQ
;
; Build example:
;   nasm -felf64 cpu_1024.asm -o cpu_1024.o
;   ld cpu_1024.o -o cpu_1024

%define SYS_exit 60

%define OP_HALT    0xFF
%define OP_MOV_IMM 0x01
%define OP_ADD     0x02
%define OP_SUB     0x03
%define OP_BEQ     0x04

section .data
    ; 16 registers x 16 limbs x 8 bytes = 2048 bytes.
    regfile: times (16 * 16) dq 0

    pc: dq 0

    ; Demo program:
    ;   r0 = 1
    ;   r1 = 2
    ;   r0 += r1
    ;   halt
    memory:
        dq OP_MOV_IMM | (0 << 8) | (0 << 16) | (1 << 24)
        dq OP_MOV_IMM | (1 << 8) | (0 << 16) | (2 << 24)
        dq OP_ADD | (0 << 8) | (1 << 16)
        dq OP_HALT

section .text
    global _start

; Zero a 1024-bit register.
; in: rcx = register index
zero_reg_1024:
    lea rdi, [rel regfile]
    mov rax, rcx
    shl rax, 7
    add rdi, rax

    mov r8, 16
.zr_loop:
    mov qword [rdi], 0
    add rdi, 8
    dec r8
    jnz .zr_loop
    ret

; Move 1024-bit register: dst = src
; in: rcx = dst, rdx = src
mov_reg_1024:
    lea rdi, [rel regfile]
    mov rax, rcx
    shl rax, 7
    add rdi, rax

    lea rsi, [rel regfile]
    mov rax, rdx
    shl rax, 7
    add rsi, rax

    mov r8, 16
.ml_loop:
    mov r9, [rsi]
    mov [rdi], r9
    add rsi, 8
    add rdi, 8
    dec r8
    jnz .ml_loop
    ret

; Add 1024-bit registers: dst += src
; in: rcx = dst, rdx = src
add_reg_1024:
    lea rdi, [rel regfile]
    mov rax, rcx
    shl rax, 7
    add rdi, rax

    lea rsi, [rel regfile]
    mov rax, rdx
    shl rax, 7
    add rsi, rax

    clc
    mov r8, 16
.ar_loop:
    mov r9, [rdi]
    adc r9, qword [rsi]
    mov [rdi], r9
    add rdi, 8
    add rsi, 8
    dec r8
    jnz .ar_loop
    ret

; Subtract 1024-bit registers: dst -= src
; in: rcx = dst, rdx = src
sub_reg_1024:
    lea rdi, [rel regfile]
    mov rax, rcx
    shl rax, 7
    add rdi, rax

    lea rsi, [rel regfile]
    mov rax, rdx
    shl rax, 7
    add rsi, rax

    clc
    mov r8, 16
.sr_loop:
    mov r9, [rdi]
    sbb r9, qword [rsi]
    mov [rdi], r9
    add rdi, 8
    add rsi, 8
    dec r8
    jnz .sr_loop
    ret

; Compare 1024-bit registers.
; in: rcx = a, rdx = b
; out: rax = 1 if equal, else 0
cmp_reg_1024_eq:
    lea rdi, [rel regfile]
    mov r8, rcx
    shl r8, 7
    add rdi, r8

    lea rsi, [rel regfile]
    mov r8, rdx
    shl r8, 7
    add rsi, r8

    mov r9, 16
    xor eax, eax
.cr_loop:
    mov r10, [rdi]
    cmp r10, [rsi]
    jne .not_eq
    add rdi, 8
    add rsi, 8
    dec r9
    jnz .cr_loop
    mov eax, 1
.not_eq:
    ret

; Load a 64-bit immediate into the low limb of a 1024-bit register.
; in: rcx = register index, rbx = imm64
load_reg_imm64:
    call zero_reg_1024

    lea rdi, [rel regfile]
    mov rax, rcx
    shl rax, 7
    add rdi, rax

    mov [rdi], rbx
    ret

_start:
    mov qword [rel pc], 0

.cpu_loop:
    mov rax, [rel pc]
    lea r11, [rel memory]
    mov rbx, [r11 + rax*8]

    mov eax, ebx
    and eax, 0xFF
    cmp eax, OP_HALT
    je .halt

    mov ecx, ebx
    shr ecx, 8
    and ecx, 0xFF

    mov edx, ebx
    shr edx, 16
    and edx, 0xFF

    mov r9, rbx
    shr r9, 24

    cmp eax, OP_MOV_IMM
    je .op_mov_imm
    cmp eax, OP_ADD
    je .op_add
    cmp eax, OP_SUB
    je .op_sub
    cmp eax, OP_BEQ
    je .op_beq
    jmp .halt

.op_mov_imm:
    mov rbx, r9
    call load_reg_imm64
    inc qword [rel pc]
    jmp .cpu_loop

.op_add:
    call add_reg_1024
    inc qword [rel pc]
    jmp .cpu_loop

.op_sub:
    call sub_reg_1024
    inc qword [rel pc]
    jmp .cpu_loop

.op_beq:
    call cmp_reg_1024_eq
    test rax, rax
    jz .beq_not_taken

    mov rax, [rel pc]
    inc rax
    mov rax, [r11 + rax*8]
    mov [rel pc], rax
    jmp .cpu_loop

.beq_not_taken:
    add qword [rel pc], 2
    jmp .cpu_loop

.halt:
    mov rax, SYS_exit
    xor rdi, rdi
    syscall
