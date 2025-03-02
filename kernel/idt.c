#include "idt.h"
#include "gdt.h"
#include "isr.h"
#include "string.h"

idt_entry_t idt[256];

void idt_init() {
  memset(&idt, 0, sizeof(idt_entry_t) * 256);

  pic_remap(32, 40);

  idt_set_gate(0, (uint32_t)isr0);
  idt_set_gate(1, (uint32_t)isr1);
  idt_set_gate(2, (uint32_t)isr2);
  idt_set_gate(3, (uint32_t)isr3);
  idt_set_gate(4, (uint32_t)isr4);
  idt_set_gate(5, (uint32_t)isr5);
  idt_set_gate(6, (uint32_t)isr6);
  idt_set_gate(7, (uint32_t)isr7);
  idt_set_gate(8, (uint32_t)isr8);
  idt_set_gate(9, (uint32_t)isr9);
  idt_set_gate(10, (uint32_t)isr10);
  idt_set_gate(11, (uint32_t)isr11);
  idt_set_gate(12, (uint32_t)isr12);
  idt_set_gate(13, (uint32_t)isr13);
  idt_set_gate(14, (uint32_t)isr14);
  idt_set_gate(15, (uint32_t)isr15);
  idt_set_gate(16, (uint32_t)isr16);
  idt_set_gate(17, (uint32_t)isr17);
  idt_set_gate(18, (uint32_t)isr18);
  idt_set_gate(19, (uint32_t)isr19);
  idt_set_gate(20, (uint32_t)isr20);
  idt_set_gate(21, (uint32_t)isr21);
  idt_set_gate(22, (uint32_t)isr22);
  idt_set_gate(23, (uint32_t)isr23);
  idt_set_gate(24, (uint32_t)isr24);
  idt_set_gate(25, (uint32_t)isr25);
  idt_set_gate(26, (uint32_t)isr26);
  idt_set_gate(27, (uint32_t)isr27);
  idt_set_gate(28, (uint32_t)isr28);
  idt_set_gate(29, (uint32_t)isr29);
  idt_set_gate(30, (uint32_t)isr30);
  idt_set_gate(31, (uint32_t)isr31);
  idt_set_gate(32, (uint32_t)isr32);
  idt_set_gate(33, (uint32_t)isr33);
  idt_set_gate(34, (uint32_t)isr34);
  idt_set_gate(35, (uint32_t)isr35);
  idt_set_gate(36, (uint32_t)isr36);
  idt_set_gate(37, (uint32_t)isr37);
  idt_set_gate(38, (uint32_t)isr38);
  idt_set_gate(39, (uint32_t)isr39);
  idt_set_gate(40, (uint32_t)isr40);
  idt_set_gate(41, (uint32_t)isr41);
  idt_set_gate(42, (uint32_t)isr42);
  idt_set_gate(43, (uint32_t)isr43);
  idt_set_gate(44, (uint32_t)isr44);
  idt_set_gate(45, (uint32_t)isr45);
  idt_set_gate(46, (uint32_t)isr46);
  idt_set_gate(47, (uint32_t)isr47);

  struct {
    uint16_t limit;
    uint32_t base;
  } __attribute__((packed)) idtr = {sizeof(idt) - 1, (uint32_t)&idt};
  __asm__ volatile("lidt %0" ::"m"(idtr));
}

void idt_set_gate(size_t index, uint32_t base) {
  idt[index].base_lo = base & 0xFFFF;
  idt[index].base_hi = (base >> 16) & 0xFFFF;

  idt[index].sel = GDT_CODE_SELECTOR;
  idt[index].always0 = 0;
  idt[index].flags = 0x8E;
}
