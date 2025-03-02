%include "isr.mac"
%include "gdt.mac"

extern exception_handler

exception_handler_wrap: 
    pusha                    

    mov ax, ds             
    push eax               
    RELOAD_SELECTORS GDT_DATA_SEL

    call exception_handler

    pop eax
    RELOAD_SELECTORS ax

    popa                   
    add esp, 8
    iret           

extern irq_handler

irq_handler_wrap:
    pusha                    

    mov ax, ds             
    push eax               
    RELOAD_SELECTORS GDT_DATA_SEL

    call irq_handler

    pop eax
    RELOAD_SELECTORS ax

    popa                   
    add esp, 8
    iret
