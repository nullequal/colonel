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

void memcpy(void *d, void *s, size_t n) {
  int *temp_d = (int *)d;
  const int *temp_s = (int *)s;
  for (; n != 0; n--) {
    *temp_d++ = *temp_s++;
  }
}

void memmove(void *d, void *s, size_t n) {
  int *temp_d = (int *)d;
  int *temp_s = (int *)s;
  if (d < s) {
    for (; n != 0; n--) {
      *temp_d++ = *temp_s++;
    }
  } else {
    for (; n != 0; n--) {
      temp_d[n - 1] = temp_s[n - 1];
    }
  }
}