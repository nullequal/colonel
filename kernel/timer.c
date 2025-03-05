#include "timer.h"
#include "isr.h"
#include "ports.h"

void pit_init() {
  irq_set_handler(0, &pit_handler);
  outb(0x43, 0x36);
  outb(0x40, 0xFF);
  outb(0x40, 0xFF);
}

void pit_handler(registers_t *regs) {}