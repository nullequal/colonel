#ifndef STRING_H
#define STRING_H

#include <stddef.h>
#include <stdint.h>

size_t strlen(const char *str);
void *memset(void *s, int c, size_t n);
void *memcpy(void *s1, void *s2, size_t n);
void *memmove(void *s1, void *s2, size_t n);

#endif