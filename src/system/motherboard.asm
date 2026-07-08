; motherboard.asm
; Board-level component model.

%include "../../include/common.inc"
%include "../../include/structs.inc"

global motherboard_reset
global motherboard_set_clock
global motherboard_attach_cpu
global motherboard_attach_gpu
global motherboard_attach_ram

motherboard_reset:
    mov rcx, motherboard_layout_size / 8
.clear:
    mov qword [rdi], 0
    add rdi, 8
    dec rcx
    jnz .clear
    ret

motherboard_set_clock:
    mov [rdi + motherboard_layout.clock_hz], rsi
    ret

motherboard_attach_cpu:
    mov [rdi + motherboard_layout.cpu], rsi
    ret

motherboard_attach_gpu:
    mov [rdi + motherboard_layout.gpu], rsi
    ret

motherboard_attach_ram:
    mov [rdi + motherboard_layout.ram], rsi
    ret
