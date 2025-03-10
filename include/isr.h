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

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();
extern void isr32();
extern void isr33();
extern void isr34();
extern void isr35();
extern void isr36();
extern void isr37();
extern void isr38();
extern void isr39();
extern void isr40();
extern void isr41();
extern void isr42();
extern void isr43();
extern void isr44();
extern void isr45();
extern void isr46();
extern void isr47();

#endif