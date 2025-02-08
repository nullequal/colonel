#include "gdt.h"

gdt_entry_t gdt[5];

void gdt_set_desc(size_t index, uint8_t access) {
  gdt[index].base_low = 0;
  gdt[index].base_middle = 0;
  gdt[index].base_high = 0;

  gdt[index].limit_low = 0xFFFF;
  gdt[index].flags = 0x0F;

  gdt[index].flags |= 0xC0;
  gdt[index].access = access;
}

void gdt_init() {
  __asm__ volatile("cli");

  // null segment
  gdt[0].base_low = 0;
  gdt[0].base_middle = 0;
  gdt[0].base_high = 0;
  gdt[0].limit_low = 0;
  gdt[0].flags = 0;
  gdt[0].access = 0;

  gdt_set_desc(1, 0x9A);
  gdt_set_desc(2, 0x92);
  gdt_set_desc(3, 0xFA);
  gdt_set_desc(4, 0xF2);

  gdt_reg_t gdtr;
  gdtr.limit = sizeof(gdt) - 1;
  gdtr.base = (uint32_t)&gdt;
  __asm__ volatile("lgdt %0" ::"m"(gdtr));
  gdt_reload_selectors();

  __asm__ volatile("sti");
}