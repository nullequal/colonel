# unit test: tty
custom_target(input: ['../boot.ld', '../boot.s'], output: 'tty', depends: [k],
              command: [get_option('env.CC'), '../tests/tty.c', '-T', '@INPUT@', '-o', '@OUTPUT@',
              '-ffreestanding', '-nostdlib', '-lgcc', '-I' + meson.project_source_root() + '/include',
              '-L' + meson.project_build_root() + '/kernel', '-lk'])