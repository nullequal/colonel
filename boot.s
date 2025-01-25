.section .multiboot # multiboot header
.align 4
.long 0x1BADB002
.long 0x00
.long -(0x1BADB002 + 0x00)

.section .text
.global _start
_start:
    mov $stack_top, %esp
    call kmain
    cli
    hlt

.section .bss
.align 16
stack_bottom:
.skip 16384
stack_top:
