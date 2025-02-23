sources = [
    'control.c',
    'gdt.c',
    'idt.c',
    'init.c',
    'isr.c',
    'kprintf.c',
    'string.c',
    'vga.c',
]

k = static_library(
    'k',
    sources,
    asm_o,
    include_directories: includes,
    c_args: ['-ffreestanding', '-Wall', '-Wextra'],
)