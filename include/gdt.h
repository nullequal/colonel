// although i use paging, in x86 segmentation is a must.
// so i initiallize a gdt with hardcoded overlapping segments

#ifndef GDT_H_
#define GDT_H_

#include <stddef.h>
#include <stdint.h>

#define GDT_CODE_SELECTOR 0x08

struct gdt_entry {
  uint16_t limit_low;
  uint16_t base_low;
  uint8_t base_middle;
  uint8_t access;
  uint8_t flags;
  uint8_t base_high;
} __attribute__((packed));

typedef struct gdt_entry gdt_entry_t;

void gdt_set_desc(size_t index, uint8_t access);
void gdt_init();

#endif