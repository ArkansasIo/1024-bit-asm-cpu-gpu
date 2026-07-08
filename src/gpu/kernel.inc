%include "../../include/common.inc"
%include "opcodes.inc"
%include "registers.inc"

; GPU kernel model notes.
; The current runnable implementation executes a simple vector add/copy dispatch loop.

%macro GPU_KERNEL_WORK_ITEM 3
    ; %1 = destination label or register, %2 = base, %3 = work-item index
%endmacro
