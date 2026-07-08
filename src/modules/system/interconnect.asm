; system interconnect module

%include "../../../include/common.inc"
%include "../../../include/structs.inc"

global bus_endpoint_connect
global bus_endpoint_clear

; in: rdi = endpoint, rsi = component ptr, rdx = port, rcx = mode
bus_endpoint_connect:
    mov [rdi + bus_endpoint.component], rsi
    mov [rdi + bus_endpoint.port], rdx
    mov [rdi + bus_endpoint.mode], rcx
    ret

bus_endpoint_clear:
    xor rax, rax
    mov [rdi + bus_endpoint.component], rax
    mov [rdi + bus_endpoint.port], rax
    mov [rdi + bus_endpoint.mode], rax
    ret
