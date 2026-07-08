; system RAM controller module

%include "../../../include/common.inc"
%include "../../../include/structs.inc"

global ram_region_init
global ram_region_contains
global ram_region_advance

; in: rdi = region, rsi = base, rdx = size, rcx = role
ram_region_init:
    mov [rdi + memory_region.base], rsi
    mov [rdi + memory_region.size], rdx
    mov [rdi + memory_region.role], rcx
    xor rax, rax
    mov [rdi + memory_region.flags], rax
    mov [rdi + memory_region.cursor], rax
    ret

; in: rdi = region, rsi = address
; out: rax = 1 if in region, else 0
ram_region_contains:
    mov rax, [rdi + memory_region.base]
    mov rcx, [rdi + memory_region.size]
    lea rdx, [rax + rcx]
    cmp rsi, rax
    jb .no
    cmp rsi, rdx
    jae .no
    mov eax, 1
    ret
.no:
    xor eax, eax
    ret

; in: rdi = region, rsi = delta
; out: rax = updated cursor
ram_region_advance:
    mov rax, [rdi + memory_region.cursor]
    add rax, rsi
    mov [rdi + memory_region.cursor], rax
    ret
