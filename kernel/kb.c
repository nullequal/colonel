#include "kb.h"

#include "controller.h"
#include "ports.h"

// TODO: make this actually a buffer
uint8_t kb_buf;
uint8_t kb_map[] = {'\0', '\0', '1',  '2',  '3',  '4',  '5',  '6', '7',  '8',
                    '9',  '0',  '-',  '=',  '\b', '\t', 'q',  'w', 'e',  'r',
                    't',  'y',  'u',  'i',  'o',  'p',  '[',  ']', '\n', '\0',
                    'a',  's',  'd',  'f',  'g',  'h',  'j',  'k', 'l',  ';',
                    '\'', '`',  '\0', '\\', 'z',  'x',  'c',  'v', 'b',  'n',
                    'm',  ',',  '.',  '/',  '\0', '*',  '\0', ' '};

void kb_handler(registers_t *regs) {
  uint8_t keycode = kb_map[inb(KB_DATA_PORT)];
  kb_buf = keycode;
}

uint8_t kb_read() {
  while (kb_buf == 0)
    ;
  uint8_t temp = kb_buf;
  kb_buf = 0;
  return temp;
}

void kb_init() { pic_clear_mask(1); }
