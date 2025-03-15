#include "isr.h"

#include "controller.h"
#include "kernel.h"
#include "timer.h"

irq_t irq_handlers[16] = {&pit_handler};

void exception_handler(registers_t regs) {
  kprintf("Exception: %d\n", regs.int_no);
  abort();
}

void irq_handler(registers_t regs) {
  pic_send_eoi(regs.int_no - 32);
  irq_t handler = irq_handlers[regs.int_no - 32];
  if (handler != 0x0) {
    handler(&regs);
  }
}