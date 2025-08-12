# 0 "hello_world.c"
# 1 "/home/jana/Si-Vision-Embedded-SW-Internship/Picolibc//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "hello_world.c"
# 1 "/usr/local/include/stdio.h" 1 3 4
# 42 "/usr/local/include/stdio.h" 3 4
# 1 "/usr/local/include/sys/cdefs.h" 1 3 4
# 45 "/usr/local/include/sys/cdefs.h" 3 4
# 1 "/usr/local/include/sys/config.h" 1 3 4
# 32 "/usr/local/include/sys/config.h" 3 4
# 1 "/usr/local/include/machine/ieeefp.h" 1 3 4
# 12 "/usr/local/include/machine/ieeefp.h" 3 4
# 1 "/usr/local/include/sys/features.h" 1 3 4
# 28 "/usr/local/include/sys/features.h" 3 4
# 1 "/usr/local/include/picolibc.h" 1 3 4





       
# 29 "/usr/local/include/sys/features.h" 2 3 4
# 13 "/usr/local/include/machine/ieeefp.h" 2 3 4
# 33 "/usr/local/include/sys/config.h" 2 3 4
# 46 "/usr/local/include/sys/cdefs.h" 2 3 4
# 1 "/usr/local/include/machine/_default_types.h" 1 3 4
# 210 "/usr/local/include/machine/_default_types.h" 3 4

# 210 "/usr/local/include/machine/_default_types.h" 3 4
typedef signed char __int8_t;




typedef unsigned char __uint8_t;



typedef short int __int16_t;




typedef short unsigned int __uint16_t;



typedef long int __int32_t;




typedef long unsigned int __uint32_t;



typedef long long int __int64_t;




typedef long long unsigned int __uint64_t;



typedef signed char __int_least8_t;

typedef unsigned char __uint_least8_t;
# 272 "/usr/local/include/machine/_default_types.h" 3 4
typedef short int __int_least16_t;

typedef short unsigned int __uint_least16_t;
# 294 "/usr/local/include/machine/_default_types.h" 3 4
typedef long int __int_least32_t;

typedef long unsigned int __uint_least32_t;
# 312 "/usr/local/include/machine/_default_types.h" 3 4
typedef long long int __int_least64_t;

typedef long long unsigned int __uint_least64_t;
# 326 "/usr/local/include/machine/_default_types.h" 3 4
typedef long long int __intmax_t;







typedef long long unsigned int __uintmax_t;







typedef int __intptr_t;

typedef unsigned int __uintptr_t;
# 47 "/usr/local/include/sys/cdefs.h" 2 3 4
# 43 "/usr/local/include/stdio.h" 2 3 4


# 1 "/usr/lib/gcc/riscv64-unknown-elf/13.2.0/include/stddef.h" 1 3 4
# 214 "/usr/lib/gcc/riscv64-unknown-elf/13.2.0/include/stddef.h" 3 4
typedef unsigned int size_t;
# 46 "/usr/local/include/stdio.h" 2 3 4

# 1 "/usr/lib/gcc/riscv64-unknown-elf/13.2.0/include/stdarg.h" 1 3 4
# 40 "/usr/lib/gcc/riscv64-unknown-elf/13.2.0/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 48 "/usr/local/include/stdio.h" 2 3 4
# 1 "/usr/local/include/sys/lock.h" 1 3 4
# 24 "/usr/local/include/sys/lock.h" 3 4


struct __lock;
typedef struct __lock * _LOCK_T;






void __retarget_lock_init(_LOCK_T *lock);
void __retarget_lock_init_recursive(_LOCK_T *lock);
void __retarget_lock_close(_LOCK_T lock);
void __retarget_lock_close_recursive(_LOCK_T lock);
void __retarget_lock_acquire(_LOCK_T lock);
void __retarget_lock_acquire_recursive(_LOCK_T lock);
void __retarget_lock_release(_LOCK_T lock);
void __retarget_lock_release_recursive(_LOCK_T lock);
# 52 "/usr/local/include/sys/lock.h" 3 4






extern struct __lock __lock___libc_recursive_mutex;
# 49 "/usr/local/include/stdio.h" 2 3 4
# 1 "/usr/local/include/sys/_types.h" 1 3 4
# 52 "/usr/local/include/sys/_types.h" 3 4
# 1 "/usr/lib/gcc/riscv64-unknown-elf/13.2.0/include/stddef.h" 1 3 4
# 359 "/usr/lib/gcc/riscv64-unknown-elf/13.2.0/include/stddef.h" 3 4
typedef unsigned int wint_t;
# 53 "/usr/local/include/sys/_types.h" 2 3 4
# 61 "/usr/local/include/sys/_types.h" 3 4
# 1 "/usr/local/include/machine/_types.h" 1 3 4
# 62 "/usr/local/include/sys/_types.h" 2 3 4


typedef long __blkcnt_t;
typedef __int64_t __blkcnt64_t;



typedef long __blksize_t;



typedef __uint64_t __fsblkcnt_t;



typedef __uint32_t __fsfilcnt_t;






typedef long _off_t;






typedef int __pid_t;






typedef short __dev_t;







typedef unsigned short __uid_t;






typedef unsigned short __gid_t;




typedef __uint32_t __id_t;







typedef unsigned short __ino_t;

typedef __uint64_t __ino64_t;
# 142 "/usr/local/include/sys/_types.h" 3 4
typedef __uint32_t __mode_t;





__extension__ typedef long long _off64_t;


typedef _off_t __off_t;
typedef __uint64_t __off64_t;

typedef _off64_t __loff_t;


typedef long __key_t;







typedef long _fpos_t;




typedef _off64_t _fpos64_t;







typedef unsigned int __size_t;
# 194 "/usr/local/include/sys/_types.h" 3 4
typedef signed int _ssize_t;
# 205 "/usr/local/include/sys/_types.h" 3 4
typedef _ssize_t __ssize_t;



typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    unsigned char __wchb[4];
    __uint32_t __ucs;
    __uint16_t __ucs2;
  } __value;
} _mbstate_t;




struct __iconv_t;
typedef struct __iconv_t *_iconv_t;






typedef unsigned long __clock_t;






typedef __int_least64_t __time_t;





typedef unsigned long __clockid_t;


typedef long __daddr_t;



typedef unsigned long __timer_t;


typedef __uint8_t __sa_family_t;



typedef __uint32_t __socklen_t;


typedef __int32_t __nl_item;
typedef unsigned short __nlink_t;
typedef long __suseconds_t;
typedef unsigned long __useconds_t;
# 50 "/usr/local/include/stdio.h" 2 3 4


# 82 "/usr/local/include/stdio.h" 3 4
typedef __uint32_t __ungetc_t;






struct __file {
 __ungetc_t unget;
 __uint8_t flags;
# 100 "/usr/local/include/stdio.h" 3 4
 int (*put)(char, struct __file *);
 int (*get)(struct __file *);
 int (*flush)(struct __file *);



};
# 118 "/usr/local/include/stdio.h" 3 4
struct __file_close {
 struct __file file;
 int (*close)(struct __file *);
};







struct __file_ext {
        struct __file_close cfile;
        __off_t (*seek)(struct __file *, __off_t offset, int whence);
        int (*setvbuf)(struct __file *, char *buf, int mode, size_t size);
};
# 148 "/usr/local/include/stdio.h" 3 4
typedef struct __file __FILE;




typedef __FILE FILE;
# 164 "/usr/local/include/stdio.h" 3 4
extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;
# 206 "/usr/local/include/stdio.h" 3 4
FILE *fdevopen(int (*__put)(char, FILE*), int (*__get)(FILE*), int(*__flush)(FILE *));
int fclose(FILE *__stream);
int fflush(FILE *stream);
# 266 "/usr/local/include/stdio.h" 3 4
int fputc(int __c, FILE *__stream);
int putc(int __c, FILE *__stream);
int putchar(int __c);



int printf(const char *__fmt, ...) __attribute__((__format__(printf,1,2)));
int fprintf(FILE *__stream, const char *__fmt, ...) __attribute__((__format__(printf,2,3)));
int vprintf(const char *__fmt, __gnuc_va_list __ap) __attribute__((__format__(printf,1,0)));
int vfprintf(FILE *__stream, const char *__fmt, __gnuc_va_list __ap) __attribute__((__format__(printf,2,0)));
int sprintf(char *__s, const char *__fmt, ...) __attribute__((__format__(printf,2,3)));
int snprintf(char *__s, size_t __n, const char *__fmt, ...) __attribute__((__format__(printf,3,4)));
int vsprintf(char *__s, const char *__fmt, __gnuc_va_list ap) __attribute__((__format__(printf,2,0)));
int vsnprintf(char *__s, size_t __n, const char *__fmt, __gnuc_va_list ap) __attribute__((__format__(printf,3,0)));
int asprintf(char **strp, const char *fmt, ...) __attribute__((__format__(printf,2,3)));
char *asnprintf(char *str, size_t *lenp, const char *fmt, ...) __attribute__((__format__(printf,3,4)));
int vasprintf(char **strp, const char *fmt, __gnuc_va_list ap) __attribute__((__format__(printf,2,0)));
char *vasnprintf(char *str, size_t *lenp, const char *fmt, __gnuc_va_list ap) __attribute__((__format__(printf,3,0)));

int fputs(const char *__str, FILE *__stream);
int puts(const char *__str);
size_t fwrite(const void *__ptr, size_t __size, size_t __nmemb,
         FILE *__stream);

int fgetc(FILE *__stream);
int getc(FILE *__stream);
int getchar(void);

int ungetc(int __c, FILE *__stream);

int scanf(const char *__fmt, ...) __attribute__((__format__(scanf,1,2)));
int fscanf(FILE *__stream, const char *__fmt, ...) __attribute__((__format__(scanf,2,3)));
int vscanf(const char *__fmt, __gnuc_va_list __ap) __attribute__((__format__(scanf,1,0)));
int vfscanf(FILE *__stream, const char *__fmt, __gnuc_va_list __ap) __attribute__((__format__(scanf,2,0)));
int sscanf(const char *__buf, const char *__fmt, ...) __attribute__((__format__(scanf,2,3)));
int vsscanf(const char *__buf, const char *__fmt, __gnuc_va_list ap) __attribute__((__format__(scanf,2,0)));

char *fgets(char *__str, int __size, FILE *__stream);



size_t fread(void *__ptr, size_t __size, size_t __nmemb,
        FILE *__stream);

void clearerr(FILE *__stream);
int ferror(FILE *__stream);
int feof(FILE *__stream);
# 328 "/usr/local/include/stdio.h" 3 4
void clearerr_unlocked(FILE *__stream);
int ferror_unlocked(FILE *__stream);
int feof_unlocked(FILE *__stream);
# 367 "/usr/local/include/stdio.h" 3 4
typedef _fpos_t fpos_t;







typedef __off_t off_t;




typedef __off64_t off64_t;




typedef _ssize_t ssize_t;






typedef __gnuc_va_list va_list;
# 401 "/usr/local/include/stdio.h" 3 4
int fgetpos(FILE * restrict stream, fpos_t * restrict pos);
FILE *fopen(const char *path, const char *mode) __attribute__((__malloc__, __malloc__(fclose,1)));
FILE *freopen(const char *path, const char *mode, FILE *stream);
FILE *fdopen(int, const char *) __attribute__((__malloc__, __malloc__(fclose,1)));
FILE *fmemopen(void *buf, size_t size, const char *mode) __attribute__((__malloc__, __malloc__(fclose,1)));
int fseek(FILE *stream, long offset, int whence);
int fseeko(FILE *stream, __off_t offset, int whence);
int fsetpos(FILE *stream, const fpos_t *pos);
long ftell(FILE *stream);
__off_t ftello(FILE *stream);
int fileno(FILE *);
void perror(const char *s);
int remove(const char *pathname);
int rename(const char *oldpath, const char *newpath);
void rewind(FILE *stream);
void setbuf(FILE *stream, char *buf);
void setbuffer(FILE *stream, char *buf, size_t size);
void setlinebuf(FILE *stream);
int setvbuf(FILE *stream, char *buf, int mode, size_t size);
FILE *tmpfile(void);
char *tmpnam (char *s);
_ssize_t getline(char **restrict lineptr, size_t *restrict n, FILE *restrict stream);
_ssize_t getdelim(char **restrict lineptr, size_t *restrict n, int delim, FILE *restrict stream);


FILE *funopen (const void *cookie,
  _ssize_t (*readfn)(void *cookie, void *buf,
    size_t n),
  _ssize_t (*writefn)(void *cookie, const void *buf,
     size_t n),
  __off_t (*seekfn)(void *cookie, __off_t off, int whence),
  int (*closefn)(void *cookie));





int getc_unlocked (FILE *);
int getchar_unlocked (void);
void flockfile (FILE *);
int ftrylockfile (FILE *);
void funlockfile (FILE *);
int putc_unlocked (int, FILE *);
int putchar_unlocked (int);
# 495 "/usr/local/include/stdio.h" 3 4
static __inline __uint32_t
__printf_float(float f)
{
 union {
  float f;
  __uint32_t u;
 } u = { .f = f };
 return u.u;
}
# 570 "/usr/local/include/stdio.h" 3 4

# 2 "hello_world.c" 2
# 1 "/usr/local/include/math.h" 1 3 4
# 40 "/usr/local/include/math.h" 3 4

# 114 "/usr/local/include/math.h" 3 4
extern double atan (double);
extern double cos (double);
extern double sin (double);
extern double tan (double);
extern double tanh (double);
extern double frexp (double, int *);
extern double modf (double, double *);
extern double ceil (double);
extern double fabs (double);
extern double floor (double);

extern double acos (double);
extern double asin (double);
extern double atan2 (double, double);
extern double cosh (double);
extern double sinh (double);
extern double exp (double);
extern double ldexp (double, int);
extern double log (double);
extern double log10 (double);
extern double pow (double, double);
extern double sqrt (double);
extern double fmod (double, double);


extern int finite (double);
extern int finitef (float);
extern int isinff (float);
extern int isnanf (float);

extern int finitel (long double);
extern int isinfl (long double);
extern int isnanl (long double);


extern int isinf (double);




extern int isnan (double);
# 181 "/usr/local/include/math.h" 3 4
    typedef float float_t;
    typedef double double_t;
# 266 "/usr/local/include/math.h" 3 4
extern int __isinff (float);
extern int __isinfd (double);
extern int __isnanf (float);
extern int __isnand (double);
extern int __fpclassifyf (float);
extern int __fpclassifyd (double);
extern int __signbitf (float);
extern int __signbitd (double);
extern int __finite (double);
extern int __finitef (float);

extern int __fpclassifyl (long double);
extern int __isinfl (long double);
extern int __isnanl (long double);
extern int __finitel (long double);
extern int __signbitl (long double);
# 344 "/usr/local/include/math.h" 3 4
int __iseqsigd(double x, double y);
int __iseqsigf(float x, float y);


int __iseqsigl(long double x, long double y);
# 367 "/usr/local/include/math.h" 3 4
int __issignalingf(float f);
int __issignaling(double d);


int __issignalingl(long double d);
# 442 "/usr/local/include/math.h" 3 4
extern double infinity (void);
extern double nan (const char *);
extern double copysign (double, double);
extern double logb (double);
extern int ilogb (double);

extern double asinh (double);
extern double cbrt (double);
extern double nextafter (double, double);
extern double rint (double);
extern double scalbn (double, int);
extern double scalb (double, double);
extern double getpayload(const double *x);
extern double significand (double);

extern double exp2 (double);
extern double scalbln (double, long int);
extern double tgamma (double);
extern double nearbyint (double);
extern long int lrint (double);
extern long long int llrint (double);
extern double round (double);
extern long int lround (double);
extern long long int llround (double);
extern double trunc (double);
extern double remquo (double, double, int *);
extern double fdim (double, double);
extern double fmax (double, double);
extern double fmin (double, double);
extern double fma (double, double, double);

extern double log1p (double);
extern double expm1 (double);

extern double acosh (double);
extern double atanh (double);
extern double remainder (double, double);
extern double gamma (double);
extern double lgamma (double);
extern double erf (double);
extern double erfc (double);
extern double log2 (double);




extern double hypot (double, double);



extern float atanf (float);
extern float cosf (float);
extern float sinf (float);
extern float tanf (float);
extern float tanhf (float);
extern float frexpf (float, int *);
extern float modff (float, float *);
extern float ceilf (float);
extern float fabsf (float);
extern float floorf (float);

extern float acosf (float);
extern float asinf (float);
extern float atan2f (float, float);
extern float coshf (float);
extern float sinhf (float);
extern float expf (float);
extern float ldexpf (float, int);
extern float logf (float);
extern float log10f (float);
extern float powf (float, float);
extern float sqrtf (float);
extern float fmodf (float, float);



extern float exp2f (float);
extern float scalblnf (float, long int);
extern float tgammaf (float);
extern float nearbyintf (float);
extern long int lrintf (float);
extern long long int llrintf (float);
extern float roundf (float);
extern long int lroundf (float);
extern long long int llroundf (float);
extern float truncf (float);
extern float remquof (float, float, int *);
extern float fdimf (float, float);
extern float fmaxf (float, float);
extern float fminf (float, float);
extern float fmaf (float, float, float);

extern float infinityf (void);
extern float nanf (const char *);
extern float copysignf (float, float);
extern float logbf (float);
extern int ilogbf (float);

extern float asinhf (float);
extern float cbrtf (float);
extern float nextafterf (float, float);
extern float rintf (float);
extern float scalbnf (float, int);
extern float scalbf (float, float);
extern float log1pf (float);
extern float expm1f (float);
extern float getpayloadf(const float *x);
extern float significandf (float);

extern float acoshf (float);
extern float atanhf (float);
extern float remainderf (float, float);
extern float gammaf (float);
extern float lgammaf (float);
extern float erff (float);
extern float erfcf (float);
extern float log2f (float);
extern float hypotf (float, float);





extern long double hypotl (long double, long double);
extern long double infinityl (void);
extern long double sqrtl (long double);
extern long double frexpl (long double, int *);
extern long double scalbnl (long double, int);
extern long double scalblnl (long double, long);
extern long double rintl (long double);
extern long int lrintl (long double);
extern long long int llrintl (long double);
extern int ilogbl (long double);
extern long double logbl (long double);
extern long double ldexpl (long double, int);
extern long double nearbyintl (long double);
extern long double ceill (long double);
extern long double fmaxl (long double, long double);
extern long double fminl (long double, long double);
extern long double roundl (long double);
extern long lroundl (long double);
extern long long int llroundl (long double);
extern long double truncl (long double);
extern long double nanl (const char *);
extern long double floorl (long double);
extern long double scalbl (long double, long double);
extern long double significandl(long double);

extern long double fabsl (long double);
extern long double copysignl (long double, long double);


extern long double atanl (long double);
extern long double cosl (long double);
extern long double sinl (long double);
extern long double tanl (long double);
extern long double tanhl (long double);
extern long double modfl (long double, long double *);
extern long double log1pl (long double);
extern long double expm1l (long double);
extern long double acosl (long double);
extern long double asinl (long double);
extern long double atan2l (long double, long double);
extern long double coshl (long double);
extern long double sinhl (long double);
extern long double expl (long double);
extern long double logl (long double);
extern long double log10l (long double);
extern long double powl (long double, long double);
extern long double fmodl (long double, long double);
extern long double asinhl (long double);
extern long double cbrtl (long double);
extern long double nextafterl (long double, long double);
extern float nexttowardf (float, long double);
extern double nexttoward (double, long double);
extern long double nexttowardl (long double, long double);
extern long double log2l (long double);
extern long double exp2l (long double);
extern long double tgammal (long double);
extern long double remquol (long double, long double, int *);
extern long double fdiml (long double, long double);
extern long double fmal (long double, long double, long double);
extern long double acoshl (long double);
extern long double atanhl (long double);
extern long double remainderl (long double, long double);
extern long double lgammal (long double);
extern long double gammal (long double);
extern long double erfl (long double);
extern long double erfcl (long double);
extern long double j0l(long double);
extern long double y0l(long double);
extern long double j1l(long double);
extern long double y1l(long double);
extern long double jnl(int, long double);
extern long double ynl(int, long double);

extern long double getpayloadl(const long double *x);
# 647 "/usr/local/include/math.h" 3 4
extern double drem (double, double);
extern float dremf (float, float);

extern long double dreml (long double, long double);
extern long double lgammal_r (long double, int *);

extern double lgamma_r (double, int *);
extern float lgammaf_r (float, int *);



extern double y0 (double);
extern double y1 (double);
extern double yn (int, double);
extern double j0 (double);
extern double j1 (double);
extern double jn (int, double);



extern float y0f (float);
extern float y1f (float);
extern float ynf (int, float);
extern float j0f (float);
extern float j1f (float);
extern float jnf (int, float);
# 693 "/usr/local/include/math.h" 3 4
extern int signgam;
# 745 "/usr/local/include/math.h" 3 4
# 1 "/usr/local/include/machine/math.h" 1 3 4
# 746 "/usr/local/include/math.h" 2 3 4






# 3 "hello_world.c" 2
# 1 "/usr/local/include/stdlib.h" 1 3 4
# 44 "/usr/local/include/stdlib.h" 3 4
# 1 "/usr/local/include/machine/ieeefp.h" 1 3 4
# 45 "/usr/local/include/stdlib.h" 2 3 4



# 1 "/usr/lib/gcc/riscv64-unknown-elf/13.2.0/include/stddef.h" 1 3 4
# 329 "/usr/lib/gcc/riscv64-unknown-elf/13.2.0/include/stddef.h" 3 4
typedef int wchar_t;
# 49 "/usr/local/include/stdlib.h" 2 3 4

# 1 "/usr/local/include/machine/stdlib.h" 1 3 4
# 51 "/usr/local/include/stdlib.h" 2 3 4

# 1 "/usr/local/include/alloca.h" 1 3 4
# 53 "/usr/local/include/stdlib.h" 2 3 4









# 1 "/usr/local/include/sys/_wait.h" 1 3 4
# 63 "/usr/local/include/stdlib.h" 2 3 4

typedef struct
{
  int quot;
  int rem;
} div_t;

typedef struct
{
  long quot;
  long rem;
} ldiv_t;


typedef struct
{
  long long int quot;
  long long int rem;
} lldiv_t;




typedef int (*__compar_fn_t) (const void *, const void *);







size_t __locale_mb_cur_max (void);




void free (void *) __attribute__((__nothrow__));


__attribute__((__noreturn__)) void _Exit (int __status);


long a64l (const char *__input);

__attribute__((__noreturn__)) void abort (void);
int abs (int);

void *aligned_alloc(size_t, size_t) __attribute__((__malloc__, __malloc__(free,1))) __attribute__ ((__alloc_align__(1)))
                         __attribute__ ((__alloc_size__(2))) __attribute__((__warn_unused_result__)) __attribute__((__nothrow__));


__uint32_t arc4random (void);
__uint32_t arc4random_uniform (__uint32_t);
void arc4random_buf (void *, size_t);


int at_quick_exit(void (*)(void));

int atexit (void (*__func)(void));
double atof (const char *__nptr);

float atoff (const char *__nptr);

int atoi (const char *__nptr);
long atol (const char *__nptr);

long long atoll (const char *__nptr);

void * bsearch (const void *__key,
                 const void *__base,
                 size_t __nmemb,
                 size_t __size,
                 __compar_fn_t _compar);
void *calloc(size_t, size_t) __attribute__((__malloc__, __malloc__(free,1))) __attribute__((__warn_unused_result__))
      __attribute__ ((__alloc_size__(1,2))) __attribute__((__nothrow__));
div_t div (int __numer, int __denom);

struct _rand48;
double drand48 (void);
double _drand48_r (struct _rand48 *);
double erand48 (unsigned short [3]);
double _erand48_r (struct _rand48 *, unsigned short [3]);

__attribute__((__noreturn__)) void exit (int __status);
void free (void *) __attribute__((__nothrow__));
char * getenv (const char *__string);




char * _findenv (const char *, int *);


extern char *suboptarg;
int getsubopt (char **, char * const *, char **);





char * initstate (unsigned, char *, size_t);


long jrand48 (unsigned short [3]);
long _jrand48_r (struct _rand48 *, unsigned short [3]);

long labs (long);

void lcong48 (unsigned short [7]);
void _lcong48_r (struct _rand48 *, unsigned short [7]);

ldiv_t ldiv (long __numer, long __denom);

long long llabs (long long);
lldiv_t lldiv (long long __numer, long long __denom);


long lrand48 (void);
long _lrand48_r (struct _rand48 *);

void *malloc(size_t) __attribute__((__malloc__, __malloc__(free,1))) __attribute__((__warn_unused_result__)) __attribute__ ((__alloc_size__(1))) __attribute__((__nothrow__));
int mblen (const char *, size_t);
size_t mbstowcs (wchar_t *restrict, const char *restrict, size_t);
int mbtowc (wchar_t *restrict, const char *restrict, size_t);

char * mkdtemp (char *);






int mkstemp (char *);


int mkstemps (char *, int);


char * mktemp (char *) __attribute__((__deprecated__("the use of `mktemp' is dangerous; use `mkstemp' instead")));


long mrand48 (void);
long _mrand48_r (struct _rand48 *);
long nrand48 (unsigned short [3]);
long _nrand48_r (struct _rand48 *, unsigned short [3]);


int posix_memalign (void **, size_t, size_t) __attribute__((__nonnull__ (1)))
     __attribute__((__warn_unused_result__));


int putenv (char *__string);


__attribute__((__noreturn__)) void
 quick_exit(int);

void qsort (void *__base, size_t __nmemb, size_t __size, __compar_fn_t _compar);
# 229 "/usr/local/include/stdlib.h" 3 4
void qsort_r (void *__base, size_t __nmemb, size_t __size, void *__thunk, int (*_compar)(void *, const void *, const void *))
             __asm__ ("" "__bsd_qsort_r");





int rand (void);

int rand_r (unsigned *__seed);


long random (void);

void *realloc(void *, size_t) __attribute__((__warn_unused_result__)) __attribute__ ((__alloc_size__(2))) __attribute__((__nothrow__));

void *reallocarray(void *, size_t, size_t) __attribute__((__warn_unused_result__)) __attribute__ ((__alloc_size__(2,3)));
void *reallocf(void *, size_t) __attribute__((__warn_unused_result__)) __attribute__ ((__alloc_size__(2)));


char * realpath (const char *restrict path, char *restrict resolved_path);


int rpmatch (const char *response);


unsigned short *
       seed48 (unsigned short [3]);
unsigned short *
       _seed48_r (struct _rand48 *, unsigned short [3]);


int setenv (const char *__string, const char *__value, int __overwrite);





char * setstate (char *);

void srand (unsigned __seed);

void srand48 (long);
void _srand48_r (struct _rand48 *, long);


void srandom (unsigned);

double strtod (const char *restrict __n, char **restrict __end_PTR);

int strfromd(char *restrict str, size_t n,
                 const char *restrict format, double fp);


float strtof (const char *restrict __n, char **restrict __end_PTR);

long double
        strtold (const char *restrict __n, char **restrict __end_PTR);


int strfromf(char *restrict str, size_t n,
                 const char *restrict format, float fp);

int strfroml (char *restrict str, size_t n,
                  const char *restrict format, long double fp);
# 303 "/usr/local/include/stdlib.h" 3 4
long strtol (const char *restrict __n, char **restrict __end_PTR, int __base);


extern long double
        strtold (const char *restrict, char **restrict);



long long
        strtoll (const char *restrict __n, char **restrict __end_PTR, int __base);

unsigned long
        strtoul (const char *restrict __n, char **restrict __end_PTR, int __base);

unsigned long long
        strtoull (const char *restrict __n, char **restrict __end_PTR, int __base);
# 339 "/usr/local/include/stdlib.h" 3 4
int system (const char *__string);

int unsetenv (const char *__string);

size_t wcstombs (char *restrict, const wchar_t *restrict, size_t);
int wctomb (char *, wchar_t);
void *valloc (size_t) __attribute__((__malloc__, __malloc__(free,1))) __attribute__((__warn_unused_result__)) __attribute__ ((__alloc_size__(1))) __attribute__((__nothrow__));

char *l64a (long __input);


int on_exit (void (*__func)(int, void *),void *__arg);
# 401 "/usr/local/include/stdlib.h" 3 4
char *__itoa (int, char *, int);
char *__utoa (unsigned, char *, int);
char *itoa (int, char *, int);
char *utoa (unsigned, char *, int);
void cfree (void *);
char *__dtoa (double, int, int, int *, int*, char**);
char *__ldtoa (long double, int, int, int *, int *, char **);
void __eprintf (const char *, const char *, unsigned int, const char *);
# 434 "/usr/local/include/stdlib.h" 3 4

# 4 "hello_world.c" 2

# 4 "hello_world.c"
int main()
{

 printf("Hello World, from Picolibc!\nEnter a number: ");
 float x = sinf(
# 8 "hello_world.c" 3 4
               3.14159265358979323846
# 8 "hello_world.c"
                   /3.0);
 printf("sine(60) = %.3f\n",x);
 exit(0);
}
