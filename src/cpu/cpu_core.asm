; cpu_core.asm
; CPU module index and integration helpers.

%include "../../include/common.inc"
%include "../../include/structs.inc"
%include "opcodes.inc"
%include "registers.inc"
%include "memory.inc"

extern cpu_execute_step

global cpu_state_init
global cpu_state_set_mode
global cpu_state_run_one

cpu_state_init:
    xor rax, rax
    mov [rdi + cpu_state.pc], rax
    mov [rdi + cpu_state.sp], rax
    mov [rdi + cpu_state.flags], rax
    mov [rdi + cpu_state.mode], rax
    ret

cpu_state_set_mode:
    mov [rdi + cpu_state.mode], rsi
    ret

; in:
;   rdi = cpu_state
;   rsi = memory
; out:
;   rax = pc
;   rdx = halt flag
cpu_state_run_one:
    jmp cpu_execute_step
