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

nasm = find_program('nasm')

assembler = generator(nasm,
           output: '@BASENAME@.o',
           arguments: ['-f', 'elf32', '@INPUT@', '-o', '@OUTPUT@'])

asmobj = assembler.process(['isr.asm', 'halt.asm', 'gdt.asm'])

k = static_library(
    'k',
    sources,
    asmobj,
    include_directories: includes,
    c_args: ['-ffreestanding', '-Wall', '-Wextra'],
)