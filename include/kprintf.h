#ifndef KPRINTF_H
#define KPRINTF_H

#include <stdarg.h>
#include <stddef.h>

char *itoa(int value, char *str);
int kprintf(const char *format, ...);

#endif