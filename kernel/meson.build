sources = ['gdt.c', 'gdt.s', 'idt.c', 'isr.c', 'isr.s', 'kprintf.c', 'string.c', 'vga.c']

k = static_library('k', sources, include_directories: includes, c_args: ['-ffreestanding', '-Wall', '-Wextra'])