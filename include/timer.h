#ifndef TIMER_H
#define TIMER_H

#include "isr.h"

void timer_handler(registers_t *regs);
void timer_init();

#endif