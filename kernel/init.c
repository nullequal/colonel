#include "gdt.h"
#include "idt.h"
#include "vga.h"

void init() {
    scr_clear();
    scr_set_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    gdt_init();
    idt_init();
}