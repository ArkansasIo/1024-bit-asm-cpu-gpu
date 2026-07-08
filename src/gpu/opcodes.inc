%include "../../include/common.inc"

; GPU opcode field helpers.
%define GPU_OP_MASK   0xFF
%define GPU_DST_SHIFT 8
%define GPU_SRC_SHIFT 16
%define GPU_IMM_SHIFT 24

%macro GPU_OP 1
    ((%1) & GPU_OP_MASK)
%endmacro

%macro GPU_DST 1
    (((%1) >> GPU_DST_SHIFT) & 0xFF)
%endmacro

%macro GPU_SRC 1
    (((%1) >> GPU_SRC_SHIFT) & 0xFF)
%endmacro
