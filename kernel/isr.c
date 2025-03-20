#include "isr.h"

#include "controller.h"
#include "kb.h"
#include "kernel.h"
#include "timer.h"
#include "vga.h"

irq_t irq_handlers[16] = {&pit_handler, &kb_handler};

void exception_handler(registers_t regs) {
  scr_clear();
  kprintf("Exception: %d\n", regs.int_no);
  kprintf("Error: %x\n", regs.err_no);
  abort();
}

void irq_handler(registers_t regs) {
  pic_send_eoi(regs.int_no - 32);
  irq_t handler = irq_handlers[regs.int_no - 32];
  if (handler != 0x0) {
    handler(&regs);
  }
}