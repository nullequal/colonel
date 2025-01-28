// although i use paging, in x86 segmentation is a must.
// so i initiallize a gdt with hardcoded overlapping segments

#include <stdint.h>
#include <stddef.h>

struct gdt_entry
{
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t flags;
    uint8_t base_high;
} __attribute__((packed));

typedef struct gdt_entry gdt_entry_t;

extern void gdt_flush(uint16_t limit, uint32_t base);
void gdt_set_desc(size_t index, uint8_t access);
void gdt_init();
