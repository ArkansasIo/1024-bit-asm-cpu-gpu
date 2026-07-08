; storage.asm
; Persistent storage device model.

%include "../../include/common.inc"
%include "../../include/structs.inc"

global storage_device_init
global storage_device_set_capacity

storage_device_init:
    xor rax, rax
    mov [rdi + storage_device.kind], rax
    mov [rdi + storage_device.capacity], rax
    mov [rdi + storage_device.io_mode], rax
    mov [rdi + storage_device.base_lba], rax
    ret

storage_device_set_capacity:
    mov [rdi + storage_device.capacity], rsi
    ret
