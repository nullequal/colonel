#include "vga.h"

// TODO: find a way to make using this variable obsolete
size_t scr_index;
uint16_t *scr_buf;

void scr_clear() {
  memset((uint16_t*)VGA_ADDR, 0x0, VGA_COLUMNS*VGA_ROWS);
}

void scr_write(const char c, const char color) {
  scr_buf[scr_index] = TEXT_CHAR(c, color);
  ++scr_index;
  // TODO: find a way to run this peroidically
  scr_flush();
}

void scr_flush() {
  uint16_t *vga_ptr = (uint16_t *)VGA_ADDR;
  size_t i = 0, j = 0;
  while (i < scr_index) {
    switch (scr_buf[i] & 0xFF) {
    case '\n':
      j = ((__builtin_ceilf(j / 79) + 1) * 79);
      break;
    case '\t':
      j += 8;
      break;
    default:
      vga_ptr[j] = scr_buf[i];
      break;
    }
    ++j;
    ++i;
  }
}
