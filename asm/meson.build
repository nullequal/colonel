nasm = find_program('nasm')

assembler = generator(
    nasm,
    output: '@BASENAME@.o',
    arguments: ['-f', 'elf32', '@INPUT@', '-o', '@OUTPUT@'],
)

asmobjs = assembler.process(['boot.asm', 'isr.asm', 'halt.asm', 'gdt.asm'])