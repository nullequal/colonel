#ifndef IDT_H_
#define IDT_H_

#include <stddef.h>
#include <stdint.h>

struct idt_entry {
  uint16_t base_lo;
  uint16_t sel;
  uint8_t always0;
  uint8_t flags;
  uint16_t base_hi;
} __attribute__((packed));

typedef struct idt_entry idt_entry_t;

struct idt_reg {
  uint16_t limit;
  uint32_t base;
} __attribute__((packed));

typedef struct idt_reg idt_reg_t;

void idt_set_gate(size_t index, uint32_t base);
void idt_init();

extern uint32_t isr_table[48];

#endif