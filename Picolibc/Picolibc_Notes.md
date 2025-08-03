# Picolibc:

- C library for 16-64 bit embedded systems
- avoids internal allocation
- tuned for small memory footprint
- focus on C & POSIX conformance
- There's bunch of target that have varying sizes of float, double, long double depending on the compiler.
- Toolchains with Picolibc:
  - Debian
  - crosstool-ng
  - LLVM embedded toolchain for ARM

- It's the default library for Zephyr.
- ![image-20250803151242513](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250803151242513.png)