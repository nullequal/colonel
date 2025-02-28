%include "gdt.mac"

gdtr:
dw 0
dd 0

global gdt_load
gdt_load:
    mov ax, [esp + 4]
    mov [gdtr], ax
    mov eax, [esp + 8]
    mov [gdtr + 2], eax
    lgdt [gdtr]
    RELOAD_SELECTORS GDT_DATA_SEL
    jmp GDT_CODE_SEL:.far
.far: 
    ret
