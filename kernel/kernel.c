#include "kernel.h"
#include "gdt.h"
#include "idt.h"
#include "string.h"
#include "timer.h"
#include "vga.h"

void init() {
  scr_set_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
  scr_clear();
  scr_enable_csr(14, 15);
  scr_move_csr(0);
  gdt_init();
  idt_init();
  pit_init(0);
}

char *itoa(int value, char *str, int base) {
  if (base < 2 || base > 36) {
    *str = '\0';
    return str;
  }
  char *ptr = str, *ptr1 = str;
  int temp1;
  do {
    temp1 = value;
    value /= base;
    *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrst"
             "uvwxyz"[35 + (temp1 - value * base)];
  } while (value);
  if (temp1 < 0)
    *ptr++ = '-';
  *ptr-- = '\0';
  char temp2;
  while (ptr1 < ptr) {
    temp2 = *ptr;
    *ptr-- = *ptr1;
    *ptr1++ = temp2;
  }
  return str;
}

int kprintf(const char *format, ...) {
  va_list ap;
  va_start(ap, format);
  int written = 0;
  while (*format != '\0') {
    size_t n = 0;
    char *str = NULL;
    if (*format != '%' || *(format + 1) == '%') {
      if (*format == '%')
        format++;
      size_t amount = 1;
      while (*(format + amount) && *(format + amount) != '%')
        amount++;
      scr_write(format, amount);
      format += amount;
      written += amount;
      continue;
    }
    format++;
    switch (*format) {
    case 'c':
      format++;
      char c = (char)va_arg(ap, int);
      scr_write(&c, 1);
      written++;
      break;
    case 'd':
      format++;
      int value = va_arg(ap, int);
      itoa(value, str, 10);
      n = strlen(str);
      scr_write(str, n);
      break;
    case 's':
      format++;
      str = va_arg(ap, char *);
      n = strlen(str);
      scr_write(str, n);
      written += n;
      break;
    default:
      format--;
      n = strlen(format);
      scr_write(format, n);
      written += n;
      format += n;
      break;
    }
  }
  va_end(ap);
  return written;
}

void abort() { halt(); }