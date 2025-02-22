# unit test: tty
executable(
    'print',
    'print.c',
    include_directories: includes,
    c_args: ['-ffreestanding'],
    link_args: ['-T', '../exec.ld', '-nostdlib'],
    link_with: [k],
    name_suffix: 'bin',
)