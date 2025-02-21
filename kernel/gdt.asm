global gdt_reload_selectors
gdt_reload_selectors: 
    mov ax, [esp+4]
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    push long [esp+8]
    push .far
    jmp [esp] 
.far: 
    ret
