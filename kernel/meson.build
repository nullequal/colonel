headers = ['vga.h', 'gdt.h']
c_sources = ['vga.c', 'gdt.c']
asm_sources = ['gdt.s']

k_inc = include_directories('.')

k = static_library('k', c_sources, asm_sources, c_args: ['-ffreestanding', '-Wall', '-Wextra'])