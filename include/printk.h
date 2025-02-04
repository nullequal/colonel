#ifndef GDT_H
#define GDT_H

#include <stddef.h>
#include <stdint.h>

#include "vga.h"

size_t strlen(const char *str);
void printk(const char *str);

#endif