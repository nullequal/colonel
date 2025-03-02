#include "timer.h"
#include "isr.h"
#include "ports.h"

void timer_init() {
  irq_set_handler(0, &timer_handler);
  outb(0x43, 0x36);
  outb(0x40, 0xFF);
  outb(0x40, 0xFF);
}

void timer_handler(registers_t *regs) {}