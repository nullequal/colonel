#include "kb.h"
#include "kernel.h"

void kmain() {
  kb_init();
  while (1)
    kprintf("%c", kb_read());
  return;
}
