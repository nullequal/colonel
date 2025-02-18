#include "gdt.h"
#include "idt.h"
#include "vga.h"

void init() {
    scr_clear();
    gdt_init();
    idt_init();
}