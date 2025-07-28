# GNU Binary Utilities

- GNU binutils is collection of tools for **manipulating binary files**, especially those generated during compilation—like object files (`.o`), executables (`.elf`, `.out`, etc.), and libraries (`.a`, `.so`).

- They are essential tools used in compilation, linking, debugging, and inspection of programs, especially in embedded systems and systems programming.

- Core Tools in GNU binutils

  | Tool        | Description                                                  | Example Command                             |
  | ----------- | ------------------------------------------------------------ | ------------------------------------------- |
  | `as`        | The GNU **assembler** – converts assembly code to machine code | `as file.s -o file.o`                       |
  | `ld`        | The GNU **linker** – links object files into an executable   | `ld file1.o file2.o -o program`             |
  | `ar`        | Creates and modifies **static libraries** (`.a` files)       | `ar rcs libmylib.a file1.o file2.o`         |
  | `nm`        | Lists **symbols** (functions, variables) in object files or binaries | `nm program.elf`                            |
  | `objcopy`   | Copies and converts object file formats                      | `objcopy -O binary program.elf program.bin` |
  | `objdump`   | Displays low-level **disassembly and headers** of binaries   | `objdump -d program.elf`                    |
  | `readelf`   | Displays **ELF-specific** info (used for Linux binaries)     | `readelf -h program.elf`                    |
  | `size`      | Shows **section sizes** (text, data, bss) in a binary        | `size program.elf`                          |
  | `strings`   | Extracts **printable text** from binary files                | `strings program.elf`                       |
  | `strip`     | Removes **debug symbols** to shrink binary size              | `strip program.elf`                         |
  | `ranlib`    | Indexes static libraries (`ar` archives) for faster linking  | `ranlib libmylib.a`                         |
  | `addr2line` | Converts memory **addresses to source file:line** (useful with crash logs) | `addr2line -e program.elf 0x08001234`       |
  | `c++filt`   | Demangles **C++ symbols** (turns them into readable names)   | `c++filt _Z1fv`                             |