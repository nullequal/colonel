#include "kprintf.h"
#include "string.h"
#include "vga.h"

void kprintf(const char *format) {
  scr_write(format, strlen(format));
}