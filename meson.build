project('colonel', 'c',
  version : '0.1',
  default_options : ['c_std=gnu99'])

# libk
k = static_library('k', 'vga.c', 'gdt.c', 'gdt.s', c_args: ['-ffreestanding', '-Wall', '-Wextra'])
# unit test: term
custom_target(input: ['boot.ld', 'boot.s'], output: 'tty', depends: [k],
              command: [get_option('env.CC'), '../tty.c', '-T', '@INPUT@', '-o', '@OUTPUT@',
              '-ffreestanding', '-nostdlib', '-lgcc', '-L' + meson.project_build_root(), '-lk'])
