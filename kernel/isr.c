#include "isr.h"

__attribute__((noreturn)) void exception_handler() {
  __asm__ volatile("cli");
  for (;;) {
    __asm__ volatile("hlt");
  }
}