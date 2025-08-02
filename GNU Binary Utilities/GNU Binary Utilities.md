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

## Tool 1: `as`

- It's the GNU assembler

- It translates the assembly language source code (e.g.: file.s or file.S or file.asm) into machine code, producing an object file (.o) that can be linked later into an executable.

- ***What happens  during assembling?***

  1- Lexical & Syntax Analysis

  - It breaks lines into **tokens** (e.g., instructions, registers, labels).

  - It checks for **syntax errors**.

  2- Symbol Table Generation

  - Labels and variable names are stored in a symbol table.

  3- Instruction Encoding

  - The assembler converts each instruction into its **binary machine code**.

  4- Section Layout

  - Code & data are organized into sections.

  5- Relocation Information

  - If your code uses **labels, symbols, or external functions**, the assembler marks those as **relocation entries**.

  - These will be resolved **later by the linker**.

  6- Output: Object File (.o)

  - The final result is a binary object file.
  - Contains:
    - Binary Code
    - Symbol Table
    - Relocation Entries
    - Section Headers

- To assemble using `as`, use the following command:

  ```bash
  as file.s -o file.o
  ```

- Example:

  ![image-20250728115933506](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250728115933506.png)

- You can inspect the object file using tools like: readelf and objdump

  - **READELF**:

    - The output of the as command is an ELF relocatable objec file, not an ELF executable file.

    - ELF is an intermediate object file for the linker

    - It contains machine code, symbols, sections, relocation info

    - Extension: .o

    - You can inspect it with:

      ```bash
      readelf -a hello.o
      ```

      Output: Displays every part of the elf file, e.g.:

      - ELF Header

        - 64-bit or 32-bit

        - Architecture (x86, ARM, etc.)

        - File type: `REL` (relocatable), `EXEC`, or `DYN`

        - Entry point (where execution starts)

      - Section Headers

        - Each section’s name, size, file offset

        - Whether it’s executable, writable, or allocated

        - Types: `.text`, `.data`, `.bss`, `.rodata`, `.symtab`, etc.

      - Symbol Tables

        - Variables, functions, labels

        - Whether local or global

        - In which section they reside

    - **Objdump**

      - Does the same things as readelf, in addition to its ability to disassemble the binary.

        e.g.:

        ```bash
        objdump -d myprog # Disassemble executable code
        ```

        ![image-20250728143407095](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250728143407095.png)

      - Useful in reverse engineering.

      - Some of the useful `objdump` commands:

        | Task                        | Command                       |
        | --------------------------- | ----------------------------- |
        | Disassemble everything      | `objdump -D hello`            |
        | Use Intel syntax            | `objdump -d -Mintel hello`    |
        | Dump section contents       | `objdump -s -j .rodata hello` |
        | View symbol table           | `objdump -t hello`            |
        | View relocations            | `objdump -r hello.o`          |
        | View ELF headers & all info | `objdump -x hello`            |
        | List section headers        | `objdump -h hello`            |
        | Disassemble only `.text`    | `objdump -d hello`            |

      - Search about Regex

- ## **Tool 2: `nm`**

  - A way to **peek inside** compiled files (`.o`, `.a`, or ELF executables) to see **what functions or variables are defined or referenced**

  - Example:

    ![image-20250728151513560](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250728151513560.png)

- ## **Tool 3:** **Linker**

  - The `ld` command is the **GNU linker** — it takes one or more **object files** (`.o`) and **links** them together to produce a final **executable** (or sometimes a shared/static library).

    - What does the `ld` do?

      - Resolves **undefined symbols** (e.g., functions you used but didn’t define)

      - Merges code/data from `.o` files and libraries

      - Assigns **memory addresses**

      - Creates the final **executable**, usually in **ELF** format on Linux

  - The output from linking process is an executable elf file.

  - Compilation flow:

    ```markdown
    file.c --> gcc -c --> file.o
    func.c --> gcc -c --> func.o
    ```

    ```bash
    ld file.o func.o -c program
    ```

  - We  use `gcc` for this step because `gcc` knows how to link system libraries automatically. We don't use ld direclty because:

    - It's low-level.

    - You must **manually specify** startup files, libraries (like `libc`), etc.

    - It doesn't automatically include the standard runtime.

  - When we link using `gcc`, It: 

    - Automatically adds the startup files
    - Links against `libc`
    - Provides all the correct flags to `ld`
    - Makes sure `main()` runs correctly

    ```bash
    >> gcc file.o func.o -o main
    >> ./main
    File main is running!
    ```

![image-20250728155317157](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250728155317157.png)	

- ## **Tool 4: Compiler** 

  - A compiler is a program that translates source code written in a high-level programming language into machine code that the computer's processor can execute.

  - Categories of Compilation Flags:

    1) -o <file>

       - Sets output filename

         ```bash
         gcc -c file.c -o file.o
         ```

    2) -c

       - compile only, no linking!

         ```bash
         gcc -c func.c file.c
         ```

    3) -S

       - Stop after generating assembly.

         ```bash
         gcc -S file.c
         ```

      4. -E

         - Stop after preprocessing. 

         - Produces .i files

           ```bash
           gcc -E file.c
           ```

      5. -Wall

         - Enables common warning 

           e.g.:

           ​	1. `-Wunused-parameter`:  Function parameter never used

           ​	2. `-Wunused-function`: Function defined but never called

           ​	3. `-Wunused-variable`: Variable declared but not used	![image-20250728163252479](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250728163252479.png)

      6. Wextra

         - Enables extra warnings

      7. Werror:

         - Treat any warnings as errors

      8. Optimization Levels

         ```bash
         gcc -O0 file.c -o programO0
         gcc -S -O2 file.c -o programO2
         gcc -S -O1 file.c -o program01
         gcc -S -Os file.c -o programOs
         ```

         

         ### `-O0` (No Optimization)

         - No code reordering, inlining, or simplification.
         - Large, slow binaries — but **easy to debug**.
         - Default level unless otherwise specified.

         ### `-O1`

         - Performs basic optimizations: dead code removal, constant folding.
         - Compiles faster than `-O2`, runs better than `-O0`.
         - Safe and conservative.

         ###  `-O2`

         - Enables more optimizations:
           - Common subexpression elimination
           - Loop optimizations
           - Inlining of small functions
           - Instruction scheduling
         - **Recommended default for release builds.**

         ###  `-O3`

         - Includes everything from `-O2`, plus:
           - Function cloning
           - Loop unrolling
           - Vectorization
           - Aggressive inlining
         - Can **increase binary size** and compile time.
         - Use when performance is more important than binary size.

         ###  `-Os`

         - Based on `-O2` but avoids optimizations that increase size.
         - Great for **embedded** or storage-constrained systems.

         ###  `-Ofast`

         - Enables `-O3` **plus**:
           - `-ffast-math`: breaks strict IEEE floating-point compliance
           - Removes some runtime checks (e.g., for NaN, INF)
         - **Not standards-compliant** but can improve speed significantly.

         ###  `-Og`

         - Introduced for **debugging optimized builds**.
         - Avoids optimizations that make debugging harder.
         - Use instead of `-O0` when you want a balance.

- ## **Tool 5: Creating Static Libraries**

​	1- Create source files
​	2- Compile them to object files
​	3- Create the static library

```bash
ar rcs libmathutils.a mathutils.o
```

​	4- Create a program that uses the library
​	5- Compile and Link with the static library

```bash
gcc main.c -L. -lmathutils -o app
```

OR

```bash
gcc main.c libmathutils.a -o app
```

