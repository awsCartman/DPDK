project('dpdk_test1', 'c',
        version: '0.1',
        default_options: ['warning_level=2', 'c_std=c11']
)

# Подключение установленного DPDK через pkg-config
dpdk_dep = dependency('libdpdk', required: true)

# Источники проекта
sources = [
    'main.c',
]

# Флаги компилятора:
# -D_DEFAULT_SOURCE — чтобы увидеть ssize_t и strnlen
# -Wno-unused-function — чтобы не ругался на неиспользуемые функции
cflags = ['-D_DEFAULT_SOURCE', '-Wno-unused-function']

# Создаём исполняемый файл
executable('dpdk_test1',
           sources,
           dependencies: dpdk_dep,
           install: true,
           c_args: cflags
)
