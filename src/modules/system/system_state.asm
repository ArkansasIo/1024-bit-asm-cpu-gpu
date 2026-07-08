; system state module

%include "../../../include/common.inc"
%include "../../../include/structs.inc"

global system_state_init
global system_state_attach_board
global system_state_attach_cpu
global system_state_attach_gpu
global system_state_attach_ram
global system_state_attach_firmware
global system_state_attach_storage
global system_state_attach_power
global system_state_attach_cooling

system_state_init:
    mov rcx, system_state_size / 8
.clear:
    mov qword [rdi], 0
    add rdi, 8
    dec rcx
    jnz .clear
    ret

system_state_attach_board:
    mov [rdi + system_state.board], rsi
    ret

system_state_attach_cpu:
    mov [rdi + system_state.cpu], rsi
    ret

system_state_attach_gpu:
    mov [rdi + system_state.gpu], rsi
    ret

system_state_attach_ram:
    mov [rdi + system_state.ram], rsi
    ret

system_state_attach_firmware:
    mov [rdi + system_state.firmware], rsi
    ret

system_state_attach_storage:
    mov [rdi + system_state.storage], rsi
    ret

system_state_attach_power:
    mov [rdi + system_state.power], rsi
    ret

system_state_attach_cooling:
    mov [rdi + system_state.cooling], rsi
    ret
