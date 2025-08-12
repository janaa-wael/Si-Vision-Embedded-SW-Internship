# How to link Picolibc as a Static Library?

1- Get Picolibc source and clone it.

```bash
git clone https://github.com/picolibc/picolibc.git
```

2- Go to picolibc directory

```bash
cd picolibc
```

3- Configure for riscv32

```bash
mkdir build
cd build

cmake .. \
  -G Ninja \
  -DCMAKE_INSTALL_PREFIX=/opt/picolibc-riscv32 \
  -DCMAKE_SYSTEM_NAME=Generic \
  -DCMAKE_SYSTEM_PROCESSOR=riscv32 \
  -DCMAKE_C_COMPILER=riscv32-unknown-elf-gcc \
  -DCMAKE_CXX_COMPILER=riscv32-unknown-elf-g++ \
  -DPICOLIBC_MULTILIB=ON

```

4- Create a cross file to support different architecture

```text
[binaries]
c = 'riscv32-unknown-elf-gcc'
ar = 'riscv32-unknown-elf-ar'
strip = 'riscv32-unknown-elf-strip'
size = 'riscv32-unknown-elf-size'

[host_machine]
system = 'none'
cpu_family = 'riscv32'
cpu = 'rv32imac'
endian = 'little'

[properties]
needs_exe_wrapper = true

[paths]
prefix = '/opt/picolibc-riscv32'

```

5- Run the following commands to build your picolibc:

```bash
meson setup build-riscv32 --cross-file=riscv32-cross.txt -Dmultilib=true
ninja -C build-riscv32
sudo ninja -C build-riscv32 install
```

These commands do the following:

- `meson setup` reads your **cross file** and the project’s `meson.build` scripts
- Meson generates a Ninja `build.ninja` file for `riscv32` target
- `ninja` actually builds picolibc for that architecture

6- Compile a C program with picolibc as a shared library
e.g.: 

```c
#include <stido.h>
int main()
{
	printf("Hello from Picolibc!\n");
	return 0;
}
```

Then, run the following command:

```bash
riscv64-unknown-elf-gcc main.c \
-g -O0 \
-fno-builtin \
--sysroot=$HOME/picolibc-install \
-specs=picolibc.specs \
-march=rv32imac -mabi=ilp32 \
--oslib=semihost \
-T a.ld \
-o a.elf

```

**Explanation:**
`--sysroot` --> tells GCC where to find Picolibc headers/libs
`-specs=picolibc.specs` --> applies the correct linker and library flags for Picolibc.
`-T a.ld` --> custom linker script
`--oslibc=semihost` --> enables semihosting syscalls (for QEMU debugigng)

7- Install QEMU if not installed

```bash
sudo apt install qemu-user qemu-system-misc
```

8- Run ELF:

```
qemu-system-riscv32 a.elf

```

