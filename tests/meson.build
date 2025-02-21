bootobj = assembler.process('../boot.asm')

# unit test: tty
executable(
    'print',
    'print.c',
    bootobj,
    include_directories: includes,
    c_args: ['-ffreestanding'],
    link_args: ['-T', '../boot.ld', '-nostdlib'],
    link_with: [k],
    name_suffix: 'bin',
)