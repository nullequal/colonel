#include "timer.h"
#include "isr.h"
#include "ports.h"

void pit_init(uint32_t freq_div) {
  uint16_t quotient = freq_div <= 1 ? 0xFFFF : PIT_CLOCK / freq_div;
  irq_set_handler(0, &pit_handler);
  outb(0x43,
       PIT_CHANNEL_0 | PIT_ACCESS_LOHI | PIT_MODE_SQUARE_WAVE | PIT_BINARY);
  outb(0x40, quotient & 0xFF);
  outb(0x40, (quotient >> 8) & 0xFF);
}

void pit_handler(registers_t *regs) {}