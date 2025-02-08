#include "string.h"

size_t strlen(const char *str) {
  const char *s;
  for (s = str; *s; ++s)
    ;
  return s - str;
}

void memset(void *s, int c, size_t n) {
  int *temp = (int *)s;
  for (; n != 0; n--)
    *temp++ = c;
}