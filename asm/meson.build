nasm = find_program('nasm')

assembler = generator(
    nasm,
    output: '@BASENAME@.o',
    arguments: ['-f', 'elf32', '@INPUT@', '-o', '@OUTPUT@'],
)

asm_sources = [
    'boot.asm',
    'gdt.asm',
    'halt.asm',
    'isr.asm',
]

asm_o = assembler.process(asm_sources)