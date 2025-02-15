#include "kprintf.h"

void kprintf(const char *format) {
  scr_write(format, strlen(format));
}