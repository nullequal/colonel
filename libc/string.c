#include "string.h"

void memset(void *s, int c, size_t n) {
  for (size_t i = 0; i < n; ++i) {
    ((int*)s)[i] = c;
  }
}

size_t strlen(const char *str) {
  const char *s;
  for (s = str; *s; ++s)
    ;
  return s - str;
}