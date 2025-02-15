sources = [
    'control.c',
    'gdt.c',
    'gdt.s',
    'halt.s',
    'idt.c',
    'isr.c',
    'isr.s',
    'kprintf.c',
    'string.c',
    'vga.c',
]

k = static_library(
    'k',
    sources,
    include_directories: includes,
    c_args: ['-ffreestanding', '-Wall', '-Wextra'],
)