; system motherboard module

%include "../../../include/common.inc"
%include "../../../include/structs.inc"

global board_clear
global board_attach_component
global board_init_default

board_clear:
    mov rcx, motherboard_layout_size / 8
.clear_loop:
    mov qword [rdi], 0
    add rdi, 8
    dec rcx
    jnz .clear_loop
    ret

; in: rdi = board layout, rsi = component pointer, rdx = slot offset
board_attach_component:
    mov [rdi + rdx], rsi
    ret

; in: rdi = board layout
board_init_default:
    call board_clear
    mov qword [rdi + motherboard_layout.clock_hz], 1000000000
    ret
