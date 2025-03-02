#ifndef IDT_H
#define IDT_H

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

void idt_init();
void idt_set_gate(size_t index, uint32_t base);

#endif