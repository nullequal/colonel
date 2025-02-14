# unit test: tty
custom_target(
    input: ['../tests/tty.c', '../boot.s', '../boot.ld'],
    output: 'tty',
    depends: [k],
    command: [
        get_option('env.CC'),
        '@INPUT0@', '@INPUT1@',
        '-T', '@INPUT2@',
        '-o', '@OUTPUT@',
        '-ffreestanding',
        '-nostdlib',
        '-lgcc',
        '-I' + meson.project_source_root() + '/include',
        '-L' + meson.project_build_root() + '/kernel',
        '-lk',
    ],
)