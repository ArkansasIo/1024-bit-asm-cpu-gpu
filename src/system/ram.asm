; ram.asm
; Main memory model.

%include "../../include/common.inc"
%include "../../include/structs.inc"

global ram_image_init
global ram_image_clear

; in: rdi = region, rsi = base, rdx = size
ram_image_init:
    mov [rdi + memory_region.base], rsi
    mov [rdi + memory_region.size], rdx
    mov qword [rdi + memory_region.role], MEMORY_ROLE_SHARED_RAM
    xor rax, rax
    mov [rdi + memory_region.flags], rax
    mov [rdi + memory_region.cursor], rax
    ret

; in: rdi = qword pointer, rsi = count
ram_image_clear:
    mov rcx, rsi
.clear:
    mov qword [rdi], 0
    add rdi, 8
    dec rcx
    jnz .clear
    ret
