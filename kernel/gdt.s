.global gdt_reload_selectors
gdt_reload_selectors: 
    movw $0x10,%ax
    movw %ax,%ds
    movw %ax,%es
    movw %ax,%fs
    movw %ax,%gs
    movw %ax,%ss
    jmp $0x08, $far
far: 
    ret
