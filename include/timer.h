#ifndef TIMER_H
#define TIMER_H

#include "isr.h"

void pit_handler(registers_t *regs);
void pit_init();

#endif