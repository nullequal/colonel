#include "timer.h"
#include "isr.h"
#include "ports.h"

void pit_init() {
  irq_set_handler(0, &pit_handler);
  outb(0x43,
       PIT_CHANNEL_0 | PIT_ACCESS_LOHI | PIT_MODE_SQUARE_WAVE | PIT_BINARY);
  outb(0x40, 0xFF);
  outb(0x40, 0xFF);
}

void pit_handler(registers_t *regs) {}