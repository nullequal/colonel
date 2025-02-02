#include "gdt.h"
#include "stdio.h"
#include "vga.h"

void kmain() {
  gdt_init();
  scr_clear();
  puts("Hello, World!");
  return;
}