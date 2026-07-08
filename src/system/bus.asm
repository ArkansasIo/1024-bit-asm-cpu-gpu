; bus.asm
; Board interconnect component model.

%include "../../include/common.inc"
%include "../../include/structs.inc"

global bus_endpoint_init
global bus_endpoint_is_connected

bus_endpoint_init:
    xor rax, rax
    mov [rdi + bus_endpoint.component], rax
    mov [rdi + bus_endpoint.port], rax
    mov [rdi + bus_endpoint.mode], rax
    ret

bus_endpoint_is_connected:
    mov rax, [rdi + bus_endpoint.component]
    test rax, rax
    setnz al
    movzx eax, al
    ret
