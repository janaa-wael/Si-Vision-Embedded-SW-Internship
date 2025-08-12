1- When calling fclose 2 times in a row for the same file, it returns successfully by returning zero in the first & returns -1 (EOF). So, the fclose behaves properly.

![image-20250806014132191](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250806014132191.png)





There's an issue in Picolibc where dynamic memory management functions, especially 'nano-malloc and 'nano-free' might overwrite some user data. An example of this is observed in the 'fclose' function in tinystdio. When calling 'fclose' which invokes bufio_close() then free() function with passing the file pointer passed to fclose at the beginning, the memory deallocation may affect the FILE structure.



This can result clearing 'unget' variable in case of 32-bit targets or 'unget' and 'flags' variables in case of 64-bit targets.

check whether it calls malloc or nano-malloc 
if it calls malloc, change the configuration in the meson build file.

fclose.c: try to use fclose() for the same file 2 times -> try it on an online compiler then 

check in C99 standard