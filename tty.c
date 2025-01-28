#include "vga.h"
#include "gdt.h"

void kmain() {
  gdt_init();
  scr_clear();
  puts("Hello, World!");
  return;
}