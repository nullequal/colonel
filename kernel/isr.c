#include "isr.h"
#include "control.h"
#include "kprintf.h"
#include "ports.h"

irq_t irq_handlers[16];

void pic_send_eoi(int irq_no) {
  if (irq_no >= 7)
    outb(PIC_SLAVE_COMMAND, PIC_EOI);
  outb(PIC_MASTER_COMMAND, PIC_EOI);
}

void pic_remap(uint8_t master_off, uint8_t slave_off) {
  uint8_t master_mask = inb(PIC_MASTER_DATA);
  uint8_t slave_mask = inb(PIC_SLAVE_DATA);

  outb(PIC_MASTER_COMMAND, PIC_INIT | PIC_IWC4_PRESENT);
  outb(PIC_SLAVE_COMMAND, PIC_INIT | PIC_IWC4_PRESENT);

  outb(PIC_MASTER_DATA, master_off);
  outb(PIC_SLAVE_DATA, slave_off);

  outb(PIC_MASTER_DATA, 0x04);
  outb(PIC_SLAVE_DATA, 0x02);

  outb(PIC_MASTER_DATA, PIC_8086_MODE);
  outb(PIC_SLAVE_DATA, PIC_8086_MODE);

  outb(PIC_MASTER_DATA, master_mask);
  outb(PIC_SLAVE_DATA, slave_mask);
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