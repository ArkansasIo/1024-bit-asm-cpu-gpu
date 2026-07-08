; gpu_core.asm
; GPU module index and integration helpers.

%include "../../include/common.inc"
%include "../../include/structs.inc"
%include "opcodes.inc"
%include "registers.inc"
%include "kernel.inc"

extern gpu_dispatch_step

global gpu_state_init
global gpu_state_set_mode
global gpu_state_run_one

gpu_state_init:
    xor rax, rax
    mov [rdi + gpu_state.pc], rax
    mov [rdi + gpu_state.work_items], rax
    mov [rdi + gpu_state.current_wi], rax
    mov [rdi + gpu_state.mode], rax
    ret

gpu_state_set_mode:
    mov [rdi + gpu_state.mode], rsi
    ret

gpu_state_run_one:
    jmp gpu_dispatch_step
