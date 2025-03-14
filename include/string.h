#ifndef STRING_H_
#define STRING_H_

#include <stddef.h>
#include <stdint.h>

size_t strlen(const char *str);
char *strcat(char *s1, const char *s2);
void *memset(void *s, int c, size_t n);
void *memcpy(void *s1, const void *s2, size_t n);
void *memmove(void *s1, const void *s2, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);

#endif