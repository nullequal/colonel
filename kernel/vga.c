#include "vga.h"

// TODO: find a way to make using this variable obsolete
size_t scr_index;
uint16_t *scr_buf;

void scr_clear()
{
  uint16_t *vga_ptr = (uint16_t *)VGA_ADDR;
  for (size_t i = 0; i < VGA_COLUMNS * VGA_ROWS; ++i)
  {
    vga_ptr[i] = (uint16_t)0x0;
  }
}

void scr_write(const char c, const char color)
{
  scr_buf[scr_index] = TEXT_CHAR(c, color);
  ++scr_index;
}

void scr_flush()
{
  uint16_t *vga_ptr = (uint16_t *)VGA_ADDR;
  for (size_t i = 0; i < scr_index; ++i)
  {
    vga_ptr[i] = scr_buf[i];
  }
}
