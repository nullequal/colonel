#include "isr.h"
#include "control.h"
#include "kprintf.h"
#include "ports.h"

irq_t irq_handlers[16];

void pic_send_eoi(int irq_no) {
  if (irq_no >= 7)
    outb(0xA0, 0x20);
  outb(0x20, 0x20);
}

void pic_remap(uint8_t pic1_off, uint8_t pic2_off) {
  outb(0x20, 0x11);
  outb(0xA0, 0x11);
  outb(0x21, pic1_off);
  outb(0xA1, pic2_off);
  outb(0x21, 0x04);
  outb(0xA1, 0x02);
  outb(0x21, 0x01);
  outb(0xA1, 0x01);
  outb(0x21, 0x0);
  outb(0xA1, 0x0);
}

void exception_handler(registers_t regs) {
  kprintf("Exception: %d\n", regs.int_no);
  abort();
}

void irq_set_handler(size_t index, irq_t handler) {
  irq_handlers[index] = handler;
}

void irq_handler(registers_t regs) {
  pic_send_eoi(regs.int_no - 32);
  irq_t handler = irq_handlers[regs.int_no - 32];
  if (handler != 0x0) {
    handler(&regs);
  }
}