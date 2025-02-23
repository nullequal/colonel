#include "kprintf.h"
#include "vga.h"

void kmain() {
  for (size_t i = 1; i < 16; ++i) {
    scr_set_color(i, VGA_COLOR_BLACK);
    kprintf("%c, %d\n", i + 64, i);
  }
  return;
}