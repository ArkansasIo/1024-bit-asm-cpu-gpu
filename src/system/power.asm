; power.asm
; Power delivery model.

%include "../../include/common.inc"
%include "../../include/structs.inc"

global power_device_init
global power_device_enable

power_device_init:
    xor rax, rax
    mov [rdi + power_state.voltage_mv], rax
    mov [rdi + power_state.current_ma], rax
    mov [rdi + power_state.thermal_limit], rax
    mov [rdi + power_state.enabled], rax
    ret

power_device_enable:
    mov qword [rdi + power_state.enabled], 1
    ret
