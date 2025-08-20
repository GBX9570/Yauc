bits 32 ; enter 32 bit mode

section .bss ; not main code
stack_top:
    resb 131072
stack_end:
; the stack flows like a glass of water.
; you put things into it from the bottom,
; and empty from the top.
; for example, if you did:
; push eax
; push ebx
; you'd empty the stack in the opposite order:
; pop ebx
; pop eax

extern gdt_setup
extern cmain

global _start

section .text ; main code
_start: ; start function
    mov esp, stack_end
    xor ebp, ebp
    call cmain