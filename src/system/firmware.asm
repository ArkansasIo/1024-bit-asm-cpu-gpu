; firmware.asm
; Boot ROM / firmware model.

%include "../../include/common.inc"
%include "../../include/structs.inc"

global firmware_image_init

; in: rdi = region, rsi = base, rdx = size
firmware_image_init:
    mov [rdi + memory_region.base], rsi
    mov [rdi + memory_region.size], rdx
    mov qword [rdi + memory_region.role], MEMORY_ROLE_FIRMWARE_ROM
    xor rax, rax
    mov [rdi + memory_region.flags], rax
    mov [rdi + memory_region.cursor], rax
    ret
