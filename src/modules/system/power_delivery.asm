; system power delivery module

%include "../../../include/common.inc"
%include "../../../include/structs.inc"

global power_state_init
global power_state_enable
global power_state_set_voltage
global power_state_set_current

power_state_init:
    xor rax, rax
    mov [rdi + power_state.voltage_mv], rax
    mov [rdi + power_state.current_ma], rax
    mov [rdi + power_state.thermal_limit], rax
    mov [rdi + power_state.enabled], rax
    ret

power_state_enable:
    mov qword [rdi + power_state.enabled], 1
    ret

power_state_set_voltage:
    mov [rdi + power_state.voltage_mv], rsi
    ret

power_state_set_current:
    mov [rdi + power_state.current_ma], rsi
    ret
