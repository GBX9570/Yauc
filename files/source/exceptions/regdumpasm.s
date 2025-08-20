section .data
    global eaxv, ebxv, ecxv, edxv
    global esiv, ediv, ebpv, espv
    global eflagsv

    eaxv:    dd 0
    ebxv:    dd 0
    ecxv:    dd 0
    edxv:    dd 0
    esiv:    dd 0
    ediv:    dd 0
    ebpv:    dd 0
    espv:    dd 0
    eflagsv: dd 0

section .text
    global capture

capture:
    mov [eaxv], eax
    mov [ebxv], ebx
    mov [ecxv], ecx
    mov [edxv], edx
    mov [esiv], esi
    mov [ediv], edi
    mov [ebpv], ebp
    mov [espv], esp
    

    pushfd
        pop dword [eflagsv]

    ret