#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdint.h>

#define PIC_MASTER_COMMAND 0x20
#define PIC_MASTER_DATA 0x21
#define PIC_SLAVE_COMMAND 0xA0
#define PIC_SLAVE_DATA 0xA1
#define PIC_EOI 0x20
#define PIC_INIT 0x10
#define PIC_IWC4_PRESENT 0x1
#define PIC_8086_MODE 0x1

void pic_send_eoi(int irq_no);
void pic_mask(int irq_no);
void pic_clear_mask(int irq_no);
void pic_remap(uint8_t master_off, uint8_t slave_off);

#endif