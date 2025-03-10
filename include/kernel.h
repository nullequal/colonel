#ifndef KERNEL_H
#define KERNEL_H

#include <stdarg.h>
#include <stddef.h>

char *itoa(int value, char *str, int base);
int kprintf(const char *format, ...);
__attribute__((noreturn)) void abort();

__attribute__((noreturn)) extern void halt();

#endif