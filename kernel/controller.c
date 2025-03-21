#include "controller.h"

#include "ports.h"

void pic_send_eoi(int irq_no) {
  if (irq_no >= 7)
    outb(PIC_SLAVE_COMMAND, PIC_EOI);
  outb(PIC_MASTER_COMMAND, PIC_EOI);
}

void pic_mask(int irq_no) {
  uint16_t port;
  if (irq_no >= 7) {
    port = PIC_SLAVE_DATA;
    irq_no -= 7;
  } else {
    port = PIC_MASTER_DATA;
  }
  outb(port, inb(port) | (1 << irq_no));
}

void pic_clear_mask(int irq_no) {
  uint16_t port;
  if (irq_no >= 7) {
    port = PIC_SLAVE_DATA;
    irq_no -= 7;
  } else {
    port = PIC_MASTER_DATA;
  }
  outb(port, inb(port) & ~(1 << irq_no));
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