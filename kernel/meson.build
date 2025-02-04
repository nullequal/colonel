sources = ['gdt.c', 'gdt.s', 'string.c', 'vga.c', 'printk.c']

k = static_library('k', sources, include_directories: includes, c_args: ['-ffreestanding', '-Wall', '-Wextra'])