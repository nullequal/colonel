.intel_syntax noprefix

gdt_reg:
.word 0
.long 0

.global gdt_flush
gdt_flush:
    mov ax, [esp+4]
    mov [gdt_reg], ax
    mov eax, [esp+8]
    mov [gdt_reg+2], eax
    lgdt [gdt_reg]        

    mov ax, 0x10      
    mov ds, ax        
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:.flush 
.flush:
    ret
