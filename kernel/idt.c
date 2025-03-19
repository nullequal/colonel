#include "idt.h"

#include "controller.h"
#include "gdt.h"
#include "string.h"

extern uint32_t isr_table[48];
idt_entry_t idt[256];

void idt_set_gate(size_t index, uint32_t base) {
  idt[index].base_lo = base & 0xFFFF;
  idt[index].base_hi = (base >> 16) & 0xFFFF;

  idt[index].sel = GDT_CODE_SELECTOR;
  idt[index].always0 = 0;
  idt[index].flags = 0x8E;
}

void idt_init() {
  memset(&idt, 0, sizeof(idt));

  pic_remap(32, 40);
  for (size_t i = 0; i < 16; ++i) {
    if (i == 2) continue;
    pic_mask(i);
  }

  for (size_t i = 0; i < 48; ++i) {
    idt_set_gate(i, isr_table[i]);
  }

  idt_reg_t idtr = {sizeof(idt) - 1, (uint32_t)&idt};
  __asm__ volatile("lidt %0" ::"m"(idtr));
}
