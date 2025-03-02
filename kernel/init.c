#include "gdt.h"
#include "idt.h"
#include "timer.h"
#include "vga.h"


void init() {
  scr_set_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
  scr_clear();
  scr_enable_csr(14, 15);
  scr_move_csr(0);
  gdt_init();
  idt_init();
  timer_init();
}