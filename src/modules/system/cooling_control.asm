; system cooling control module

%include "../../../include/common.inc"
%include "../../../include/structs.inc"

global cooling_state_init
global cooling_state_set_temperature
global cooling_state_set_fan
global cooling_state_enable

cooling_state_init:
    xor rax, rax
    mov [rdi + cooling_state.fan_rpm], rax
    mov [rdi + cooling_state.temp_c], rax
    mov [rdi + cooling_state.policy], rax
    mov [rdi + cooling_state.enabled], rax
    ret

cooling_state_set_temperature:
    mov [rdi + cooling_state.temp_c], rsi
    ret

cooling_state_set_fan:
    mov [rdi + cooling_state.fan_rpm], rsi
    ret

cooling_state_enable:
    mov qword [rdi + cooling_state.enabled], 1
    ret
