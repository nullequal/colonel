#include "vga.h"

void scr_clear()
{
  uint16_t *vga_ptr = (uint16_t *)VGA_ADDR;
  for (size_t i = 0; i < VGA_COLUMNS * VGA_ROWS; ++i)
  {
    vga_ptr[i] = (uint16_t)0x0;
  }
}

void scr_flush()
{
  uint16_t *vga_ptr = (uint16_t *)VGA_ADDR;
  for (size_t i = 0; i < scr_index; ++i) {
    vga_ptr[i] = scr_buf[i];
  }
}

size_t strlen(const char *str)
{
  const char *s;
  for (s = str; *s; ++s)
    ;
  return s - str;
}

void putchar(const char c)
{
  scr_buf[scr_index] = TEXT_CHAR(c, DEFAULT_COLOR);
  ++scr_index;
  // TODO: somehow run this periodically
  scr_flush();
}

void puts(const char *str)
{
  for (size_t i = 0; i < strlen(str); ++i)
  {
    putchar(str[i]);
  }
}
