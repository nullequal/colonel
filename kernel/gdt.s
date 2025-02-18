.global gdt_reload_selectors
gdt_reload_selectors: 
    movw 4(%esp),%ax
    movw $0x10,%ax
    movw %ax,%ds
    movw %ax,%es
    movw %ax,%fs
    movw %ax,%gs
    movw %ax,%ss
    pushl 8(%esp)
    push $far
    ljmp *(%esp)
far: 
    ret
