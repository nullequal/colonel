#include "printk.h"

void printk(const char *str) {
  for (size_t i = 0; i < strlen(str); ++i) {
    scr_write(str[i], DEFAULT_COLOR);
  }
}