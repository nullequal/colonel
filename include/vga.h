#ifndef VGA_H_
#define VGA_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define VGA_ADDR 0xb8000

#define VGA_ROWS 25
#define VGA_COLUMNS 80

// x = character, y = color
#define VGA_CHAR(x, y) ((x) | (y) << 8)

enum {
  VGA_COLOR_BLACK = 0x0,
  VGA_COLOR_BLUE = 0x1,
  VGA_COLOR_GREEN = 0x2,
  VGA_COLOR_CYAN = 0x3,
  VGA_COLOR_RED = 0x4,
  VGA_COLOR_MAGENTA = 0x5,
  VGA_COLOR_BROWN = 0x6,
  VGA_COLOR_LIGHT_GREY = 0x7,
  VGA_COLOR_DARK_GREY = 0x8,
  VGA_COLOR_LIGHT_BLUE = 0x9,
  VGA_COLOR_LIGHT_GREEN = 0xA,
  VGA_COLOR_LIGHT_CYAN = 0xB,
  VGA_COLOR_LIGHT_RED = 0xC,
  VGA_COLOR_LIGHT_MAGENTA = 0xD,
  VGA_COLOR_LIGHT_BROWN = 0xE,
  VGA_COLOR_WHITE = 0xF,
};

void scr_enable_csr(uint8_t start_scanline, uint8_t end_scanline);
void scr_disable_csr();
void scr_move_csr(uint16_t pos);

void scr_clear();
void scr_set_color(uint8_t fg, uint8_t bg);
void scr_write(const char *s, size_t n);
void scr_flush();

#endif