#include "vga.h"

// TODO: find a way to make using this variable obsolete
size_t unflushed_count;
size_t scr_pos_x;
size_t scr_pos_y;
char *scr_buf;

void scr_clear() { memset((uint16_t *)VGA_ADDR, 0x0, VGA_COLUMNS * VGA_ROWS); }

void scr_write(const char c) {
  *scr_buf++ = c;
  ++unflushed_count;
  // TODO: find a way to run this periodically
  scr_flush();
}

void scr_flush() {
  uint16_t *vga_ptr = (uint16_t *)VGA_ADDR;
  for (; unflushed_count != 0; unflushed_count--) {
    switch (*(scr_buf - unflushed_count)) {
    case '\n':
      ++scr_pos_y;
      scr_pos_x = 0;
      break;
    case '\t':
      scr_pos_x += 8;
      break;
    default:
      vga_ptr[scr_pos_x + (VGA_COLUMNS * scr_pos_y)] =
          TEXT_CHAR(*(scr_buf - unflushed_count), DEFAULT_COLOR);
      if (++scr_pos_x >= VGA_COLUMNS) {
        ++scr_pos_y;
        scr_pos_x -= VGA_COLUMNS;
      }
      break;
    }
  }
}
