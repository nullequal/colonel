#ifndef ISR_H
#define ISR_H

#include <stddef.h>
#include <stdint.h>

#define PIC_MASTER_COMMAND 0x20
#define PIC_MASTER_DATA 0x21
#define PIC_SLAVE_COMMAND 0xA0
#define PIC_SLAVE_DATA 0xA1
#define PIC_EOI 0x20
#define PIC_INIT 0x10
#define PIC_IWC4_PRESENT 0x1
#define PIC_8086_MODE 0x1

struct registers {
  uint32_t ds;
  uint32_t edi, esi, ebp, ignored, ebx, edx, ecx, eax;
  uint32_t int_no, err_no;
  uint32_t eip, cs, eflags, esp, ss;
};

typedef struct registers registers_t;

typedef void (*irq_t)(registers_t *);

void pic_send_eoi(int irq_no);
void pic_mask(int irq_no);
void pic_clear_mask(int irq_no);
void pic_remap(uint8_t master_off, uint8_t slave_off);

__attribute__((noreturn)) void exception_handler(registers_t regs);
void irq_handler(registers_t regs);

#endif