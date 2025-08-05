# QEMU

- What can QEMU do?

  - Emulator Mode:

    - QEMU emulates one CPU architecture on another.

    - Example: Run an ARM or RISC-V OS on an x86 PC.

    - Useful for embedded systems development, OS kernel development & cross-platform testing.

  - Virtualizer Mode (with KVM)
    - When used with **KVM** (Kernel-based Virtual Machine) on Linux, QEMU can virtualize a system at near-native speed.
    - In this mode, QEMU uses hardware virtualization extensions like Intel VT-x or AMD-V

- Why use QEMU?

  - Run different operating systems (Linux, Wondows, FreeBSD, etc.) on your machine.
  - Test or debug system-level code safely
  - Emulate platforms like ARM, MIPS, RISC-V, PowerPC, etc.
  - Create virtual devices (storage, network cards, serial ports, etc.)

- How to emulate a system (e.g.: riscv32)?

  - Install QEMU with riscv32 support

    ```bash
    sudo apt update
    sudo apt install qemu-system-riscv qemu-user
    ```

    

12/2024	

1.8.8 (old)

line 49 newlib/libc/stdlib.c/nano-free.c

check whether the issue exists in the main

There's an issue in Picolibc where dynamic memory management functions, especially 'nano-malloc and 'nano-free' might overwrite some user data. An example of this is observed in the 'fclose' function in tinystdio. When calling 'fclose' which invokes bufio_close() then free() function with passing the file pointer passed to fclose at the beginning, the memory deallocation may affect the FILE structure.



This can result clearing 'unget' variable in case of 32-bit targets or 'unget' and 'flags' variables in case of 64-bit targets.

check whether it calls malloc or nano-malloc 
if it calls malloc, change the configuration in the meson build file.

fclose.c: try to use fclose() for the same file 2 times -> try it on an online compiler then 

check in C99 standard