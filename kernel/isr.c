#include "isr.h"
#include "control.h"
#include "kprintf.h"

void exception_handler(registers_t regs) {
  kprintf("Exception: %d", regs.int_no);
  abort();
}