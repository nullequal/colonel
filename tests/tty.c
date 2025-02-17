#include "kprintf.h"
#include "vga.h"

void kmain() {
  scr_clear();
  kprintf("Hello, World!\n");
  return;
}