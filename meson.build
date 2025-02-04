project('colonel', 'c',
  version : '0.1',
  default_options : ['c_std=gnu99'])

# kernel
includes = include_directories('include')
subdir('kernel')
# unit test: term
custom_target(input: ['boot.ld', 'boot.s'], output: 'tty', depends: [k],
              command: [get_option('env.CC'), '../tty.c', '-T', '@INPUT@', '-o', '@OUTPUT@',
              '-ffreestanding', '-nostdlib', '-lgcc', '-I' + meson.project_source_root() + '/include',
              '-L' + meson.project_build_root() + '/kernel', '-lk'])