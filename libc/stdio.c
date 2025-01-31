#include "stdio.h"

void putchar(const char c)
{
  scr_write(c, DEFAULT_COLOR);
  // TODO: somehow run this periodically
  scr_flush();
}

void puts(const char *str)
{
  for (size_t i = 0; i < strlen(str); ++i)
  {
    putchar(str[i]);
  }
  putchar('\n');
}