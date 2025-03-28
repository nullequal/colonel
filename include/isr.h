#ifndef ISR_H_
#define ISR_H_

#include <stddef.h>
#include <stdint.h>

struct registers {
  uint32_t ds;
  uint32_t edi, esi, ebp, ignored, ebx, edx, ecx, eax;
  uint32_t int_no, err_no;
  uint32_t eip, cs, eflags, esp, ss;
};

typedef struct registers registers_t;

typedef void (*irq_t)(registers_t *);

__attribute__((noreturn)) void exception_handler(registers_t regs);
void irq_handler(registers_t regs);

#endif