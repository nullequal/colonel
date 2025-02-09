#include "kprintf.h"

void kprintf(const char *format) {
  for (size_t i = 0; i < strlen(format); ++i) {
    scr_write(format[i], DEFAULT_COLOR);
  }
}