#include "kprintf.h"
#include "vga.h"

void kmain() {
  for (size_t i = 0; i < 15; ++i) {
    scr_set_color(i, VGA_COLOR_BLACK);
    kprintf("%c, %d\n", i + 64, i);
  }
  return;
}