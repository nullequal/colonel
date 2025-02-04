#include "gdt.h"
#include "vga.h"

size_t strlen(const char *str) {
  const char *s;
  for (s = str; *s; ++s)
    ;
  return s - str;
}

void printk(const char* str) {
  for (size_t i = 0; i < strlen(str); ++i) {
    scr_write(str[i], DEFAULT_COLOR);
  }
}

void kmain() {
  gdt_init();
  scr_clear();
  printk("Hello, World!\n");
  return;
}