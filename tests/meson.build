exec_ld = meson.current_source_dir() + '/exec.ld'

# unit test: print
executable(
    'print',
    'print.c',
    include_directories: includes,
    c_args: ['-ffreestanding'],
    link_args: ['-T', exec_ld, '-nostdlib'],
    link_with: [k],
    name_suffix: 'bin',
)

# unit test: input
executable(
    'input',
    'input.c',
    include_directories: includes,
    c_args: ['-ffreestanding'],
    link_args: ['-T', exec_ld, '-nostdlib'],
    link_with: [k],
    name_suffix: 'bin',
)