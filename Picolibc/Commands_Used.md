Meson Build Command:
~~~~~~~~~~~~~~~~~~~~
meson setup ../../picolibc-build \
  --cross-file=riscv32-cross.txt \
  --prefix=$HOME/picolibc-install

ninja -C ../../picolibc-build
ninja -C ../../picolibc-build install

Cross-file Contents:
~~~~~~~~~~~~~~~~~~~~
[binaries]
c = 'riscv64-unknown-elf-gcc'
ar = 'riscv64-unknown-elf-ar'
strip = 'riscv64-unknown-elf-strip'

[host_machine]
system = 'none'
cpu_family = 'riscv32'
cpu = 'rv32imac'
endian = 'little'


RISCV Compilation Command:
~~~~~~~~~~~~~~~~~~~~~~~~~~~
riscv64-unknown-elf-gcc main.c \
  -g -O0 -fno-builtin -fno-builtin-sinf \
  --sysroot=$HOME/picolibc-install \
  -specs=picolibc.specs \
  -march=rv32imac -mabi=ilp32 \
  --oslib=semihost \
  -T a.ld \
  -o a.elf


QEMU RISCV32 Command:
~~~~~~~~~~~~~~~~~~~~~~
qemu-system-riscv32 \
  -machine virt -cpu rv32 -nographic \
  -semihosting-config enable=on \
  -monitor none -serial mon:stdio \
  -bios none \
  -kernel a.elf

qemu-system-riscv32 \
  -machine virt -cpu rv32 -nographic \
  -semihosting-config enable=on \
  -monitor none -serial mon:stdio \
  -bios none \
  -kernel a.elf \
  -S -gdb tcp::1234


| Question                        | Answer                                                                               |
| ------------------------------- | ------------------------------------------------------------------------------------ |
| What is the system copy?        | The globally installed version of Picolibc (in `/usr/local/...`)                     |
| Why did you have more than one? | You cloned it locally to edit, but the system was still using the old installed one  |
| Why wasn’t your edit used?      | You didn’t install the new build, so your compiler still used the old library        |
| How did you fix it?             | You ran `sudo ninja -C build install` to overwrite the system copy with your changes |

Using GDB With QEMU Command:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
gdb-multiarch a.elf


GDB USeful Commands:
~~~~~~~~~~~~~~~~~~~~
1- list <funtion_name> --> prints the body of the function & its signature


int
fclose(FILE *f)
{
        struct __file_close *cf = (struct __file_close *) f;
        if ((f->flags & __SCLOSE) && cf->close) {
                /*
                 * File has 'close' function, call it
                 */
                return (*cf->close)(f);
        }
        return 0;
}
   
