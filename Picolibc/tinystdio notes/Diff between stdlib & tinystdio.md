# Difference Between `stdio` and `tinystdio` in Picolibc

## `stdio` in Picolibc

- Picolibc is tailored for **small embedded systems**, so its `stdio` is much lighter than glibc’s.
- Key characteristics:
  1. **Compact and configurable** compared to glibc/newlib.
  2. Can be built in multiple modes:
     - **Full `stdio`** → provides broader functionality (wide I/O, formatting, floating-point support if enabled, etc.).
     - **`tinystdio`** → a reduced-size variant optimized for flash and RAM savings.

------

## `tinystdio` in Picolibc

- A **minimal implementation** of the C standard I/O library (`stdio.h`).
- Provides only essential features (`printf`, `scanf`, `fopen`, etc.) with much simpler and smaller code.

### Why `tinystdio` Exists

- Full `stdio` (from glibc/newlib) can take tens of KB of code space.
- Many embedded applications only require **basic text I/O**.
- `tinystdio` cuts down size dramatically while covering the majority of use cases.

### Features & Trade-offs

- Replaces the standard I/O functions (`printf`, `puts`, etc.) with **smaller, simpler versions**.
- Prioritizes **ROM/RAM savings** over:
  - Execution speed
  - POSIX completeness
  - Advanced functionality (locales, wide characters, complex format specifiers).
- Often paired with **`minimal-printf`**-style functionality on microcontrollers.
- Configurable at build time as part of Picolibc.

------

👉 In short:

- **`stdio` (full mode)** = More complete, closer to standard C/POSIX, heavier.
- **`tinystdio`** = Lean, embedded-oriented, with essential functionality only.

Speed Test Case:

![image-20250824050058022](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250824050058022.png)

Size Test Case:
![image-20250824050158843](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250824050158843.png)

### Size of text section when using stdio vs tinystdio

- `stdio`:![image-20250819120112423](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250819120112423.png)

- `tinystdio`:![image-20250819122040745](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250819122040745.png)

**Stdio:**

![image-20250819164806361](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250819164806361.png)

![image-20250819183718936](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250819183718936.png)

**Tinystdio:**

![image-20250819165827608](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250819165827608.png)

![image-20250819174358693](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250819174358693.png)

![image-20250819182620828](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250819182620828.png)

