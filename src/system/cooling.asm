; cooling.asm
; Thermal management model.

%include "../../include/common.inc"
%include "../../include/structs.inc"

global cooling_device_init
global cooling_device_enable

cooling_device_init:
    xor rax, rax
    mov [rdi + cooling_state.fan_rpm], rax
    mov [rdi + cooling_state.temp_c], rax
    mov [rdi + cooling_state.policy], rax
    mov [rdi + cooling_state.enabled], rax
    ret

cooling_device_enable:
    mov qword [rdi + cooling_state.enabled], 1
    ret
