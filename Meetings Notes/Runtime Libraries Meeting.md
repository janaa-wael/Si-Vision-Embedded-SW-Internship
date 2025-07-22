- Runtime Libraries

  - intro to runtime lib
  - c99 standard  headers
    - stdint
    - string,h
    - math.h
    - stdio.h
    - stdio.h
    - stdlib.h
  - Advanced topics (foritfy source, ctype.h, locales)
  - supported lib in MWDT

  -----------------------------------------------

  a set of helper function and routines that support a program during execution, providing features like

  ​	memory allocation, i/o operations

- c runtime library

- c++ runtime lib

- host lib

- compiler specific lib

- vector lib

- linear algebra lib



- C99 standard headers:

  - headers contain functions

- stdint.h

  - fixed-width integer types ensure consistent size
  - these types improve code portability across platforms
  - stdint.h defines exact-width int types
  - examples include uint8_t, int16_t, uin32_t

- string.h

  - memory & string operations
  - critical functions: memcpy, memset, strcmp
    - strcmp is used in dhrystone source code
      - dhrystone is a benchmark standard to estimate the processor performance
    - memcpy is critical in application with data copying (because it consumes time)
  - known issues:
    - byte-byte operations
    - alignment handling
    - optimizing for size vs optimizing for speed

- Byte-Byte vs Word-Word operations

  - word-word is 4 times faster than byte-byte

    ``````````````````````````````
    void* memcpy(void* dest, const void* src, size_t n)
    {
    	char* d = dest;
    	const char* s = src;
    	while(n--) *d++ = *s++;
    	return dest;
    }
    `````````````````````````````
    uint32_t *d32 = (uin32_t*)d;
    sint32_t *s32 = (sin32_t*)d;
    while(n >= 4) 
    {
    	*d32++ = *s32++;
    	n -= 4;
    }
    ``````````````````````````````

    Which one is better?

    - It depends! 
    - if it's divisible by 4 
      - if you optimize speed: second one
      - if you optimize size: first one
    - ??? context switching in memcpy?
    - LONG LONG INT COPIES MORE THAN 4 bytes.
    - if size is too large on linux os, it can use DMA
    - if you have problem with memcpy >> implement a custom one.

  - 