gdt_reg:
.word 0
.long 0

.global gdt_flush
gdt_flush: 
    movw 4(%esp),%ax
    movw %ax,gdt_reg
    movl 8(%esp),%eax
    movl %eax,gdt_reg+2
    lgdt gdt_reg
    movw $0x10,%ax
    movw %ax,%ds
    movw %ax,%es
    movw %ax,%fs
    movw %ax,%gs
    movw %ax,%ss
    jmp 0x08:gdt_flush.flush
gdt_flush.flush: 
    ret
