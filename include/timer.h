#ifndef TIMER_H
#define TIMER_H

#include "isr.h"

#define PIT_CHANNEL_0_PORT 0x40
#define PIT_COMMAND 0x43
#define PIT_CHANNEL_0 0x0
#define PIT_ACCESS_LOHI 0x30
#define PIT_MODE_SQUARE_WAVE 0x6
#define PIT_BINARY 0x0

void pit_handler(registers_t *regs);
void pit_init();

#endif