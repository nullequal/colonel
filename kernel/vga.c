#include "vga.h"
#include "ports.h"

uint8_t scr_color;
size_t scr_pos_x;
size_t scr_pos_y;
// TODO: find a way to make using this variable obsolete
size_t unflushed_count;
char *scr_buf;

void scr_enable_csr(uint8_t start_scanline, uint8_t end_scanline) {
  outb(0x3D4, 0x0A);
  outb(0x3D5, (inb(0x3D5) & 0xC0) | start_scanline);
  outb(0x3D4, 0x0B);
  outb(0x3D5, (inb(0x3D5) & 0xE0) | end_scanline);
}

void scr_disable_csr() {
  outb(0x3D4, 0x0A);
  outb(0x3D5, 0x20);
}

void scr_move_csr(uint16_t pos) {
  outb(0x3D4, 0x0F);
  outb(0x3D5, (uint8_t)(pos & 0xFF));
  outb(0x3D4, 0x0E);
  outb(0x3D5, (uint8_t)((pos >> 8) & 0xFF));
}

void scr_clear() {
  for (size_t i = 0; i < VGA_COLUMNS * VGA_ROWS; ++i) {
    ((uint16_t *)VGA_ADDR)[i] = 0x0 | (scr_color << 8);
  }
}

void scr_set_color(uint8_t fg, uint8_t bg) { scr_color = fg | (bg << 4); }

void scr_write(const char *s, size_t n) {
  unflushed_count += n;
  for (; n != 0; n--) {
    *scr_buf++ = *s++;
  }
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
          VGA_CHAR(*(scr_buf - unflushed_count), scr_color);
      if (++scr_pos_x >= VGA_COLUMNS) {
        ++scr_pos_y;
        scr_pos_x -= VGA_COLUMNS;
      }
      break;
    }
  }
  scr_move_csr(scr_pos_x + (VGA_COLUMNS * scr_pos_y));
}