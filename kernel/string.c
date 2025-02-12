#include "string.h"

size_t strlen(const char *str) {
  const char *s;
  for (s = str; *s; ++s)
    ;
  return s - str;
}

void *memset(void *s, int c, size_t n) {
  int *temp = (int *)s;
  for (; n != 0; n--)
    *temp++ = c;
  return s;
}

void *memcpy(void *s1, void *s2, size_t n) {
  int *temp1 = (int *)s1;
  const int *temp2 = (int *)s2;
  for (; n != 0; n--) {
    *temp1++ = *temp2++;
  }
  return s1;
}

void *memmove(void *s1, void *s2, size_t n) {
  int *temp1 = (int *)s1;
  int *temp2 = (int *)s2;
  if (s1 < s2) {
    for (; n != 0; n--) {
      *temp1++ = *temp2++;
    }
  } else {
    for (; n != 0; n--) {
      temp1[n - 1] = temp2[n - 1];
    }
  }
  return s1;
}