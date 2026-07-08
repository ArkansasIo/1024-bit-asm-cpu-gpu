%include "../../include/common.inc"

; GPU register model notes.

%define GPU_VECTOR_LIMBS LIMBS_1024
%define GPU_VECTOR_BYTES  BYTES_PER_1024_VALUE

%macro GPU_VECTOR_OFFSET 1
    ((%1) * GPU_VECTOR_BYTES)
%endmacro
