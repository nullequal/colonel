# unit test: tty
executable(
    'tty',
    'tty.c',
    '../boot.s',
    include_directories: includes,
    c_args: ['-ffreestanding'],
    link_args: ['-T', '../boot.ld', '-nostdlib'],
    link_with: [k],
    name_suffix: 'bin',
)