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

  gdt_set_desc(1, 0x9A);
  gdt_set_desc(2, 0x92);
  gdt_set_desc(3, 0xFA);
  gdt_set_desc(4, 0xF2);

  gdt_load(sizeof(gdt) - 1, (uint32_t)&gdt);

  __asm__ volatile("sti");
}