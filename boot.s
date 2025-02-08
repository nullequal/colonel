# multiboot header
.section .multiboot
.align 4
.long 0x1BADB002 # magic
.long 0x00 # flags
.long -(0x1BADB002 + 0x00) # checksum

.section .bss
.align 16
stack_bottom:
.skip 16384
stack_top:

.section .text
.global _start
_start:
    movl $stack_top, %esp
    call gdt_init
    call kmain
    cli
    hlt
