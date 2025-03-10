#include "timer.h"
#include "controller.h"
#include "ports.h"

void pit_init(uint32_t freq_div) {
  pic_clear_mask(0);
  outb(0x43,
       PIT_CHANNEL_0 | PIT_ACCESS_LOHI | PIT_MODE_SQUARE_WAVE | PIT_BINARY);
  uint16_t quotient = freq_div <= 1 ? 65535 : PIT_CLOCK / freq_div;
  outb(0x40, quotient & 0xFF);
  outb(0x40, (quotient >> 8) & 0xFF);
}

void pit_handler(registers_t *regs) {}