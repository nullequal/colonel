project('colonel', 'c',
  version : '0.1',
  default_options : ['c_std=gnu99'])

# kernel
subdir('kernel')
# c library
subdir('libc')
# unit test: term
custom_target(input: ['boot.ld', 'boot.s'], output: 'tty', depends: [k, c],
              command: [get_option('env.CC'), '../tty.c', '-T', '@INPUT@', '-o', '@OUTPUT@',
              '-ffreestanding', '-nostdlib', '-lgcc', '-I' + meson.project_source_root() + '/kernel',
              '-I' + meson.project_source_root() + '/libc', '-L' + meson.project_build_root() + '/kernel',
              '-L' + meson.project_build_root() + '/libc', '-lk', '-lc'])