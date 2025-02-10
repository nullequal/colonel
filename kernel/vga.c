#include "vga.h"
#include <string.h>

// TODO: find a way to make using this variable obsolete
size_t unflushed_count;
size_t scr_pos;
char *scr_buf;

void scr_clear() { memset((uint16_t *)VGA_ADDR, 0x0, VGA_COLUMNS * VGA_ROWS); }

void scr_write(const char c) {
  *scr_buf++ = c;
  ++unflushed_count;
  // TODO: find a way to run this peroidically
  scr_flush();
}

void scr_flush() {
  uint16_t *vga_ptr = (uint16_t *)VGA_ADDR;
  for (; unflushed_count != 0; unflushed_count--) {
    switch (*(scr_buf - unflushed_count)) {
    case '\n':
      scr_pos = ((__builtin_ceilf(scr_pos / (float)VGA_COLUMNS)) * VGA_COLUMNS);
      break;
    case '\t':
      scr_pos += 8;
      break;
    default:
      vga_ptr[scr_pos] = TEXT_CHAR(*(scr_buf - unflushed_count), DEFAULT_COLOR);
      ++scr_pos;
      break;
    }
  }
}
