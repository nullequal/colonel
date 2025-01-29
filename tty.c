#include "gdt.h"
#include "stdio.h"

void kmain()
{
  gdt_init();
  scr_clear();
  puts("Hello, World!");
  return;
}