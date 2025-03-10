sources = [
    'controller.c',
    'gdt.c',
    'idt.c',
    'isr.c',
    'kernel.c',
    'kprintf.c',
    'string.c',
    'timer.c',
    'vga.c',
]

k = static_library(
    'k',
    sources,
    asm_o,
    include_directories: includes,
    c_args: ['-ffreestanding', '-Wall', '-Wextra'],
)