; multiboot header
section .multiboot
align 4
dd 0x1BADB002 ; magic
dd 0x00 ; flags
dd -(0x1BADB002 + 0x00) ; checksum

section .bss
align 16
resb 16384
stack_space:

section .text
extern init
extern kmain
extern halt

global _start
_start:
    mov esp, stack_space
    call init
    call kmain
    jmp halt
