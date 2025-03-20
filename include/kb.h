#ifndef KB_H_
#define KB_H_

#include <stdint.h>

#include "isr.h"

#define KB_DATA_PORT 0x60
#define KB_STATUS_REG 0x64
#define KB_COMMAND_REG 0x64

void kb_handler(registers_t *regs);
uint8_t kb_read();
void kb_init();

#endif
