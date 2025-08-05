# Bug Notes:

- fclose()

  - In C99, the `fclose` function is used to close a file that was previously opened using functions like `fopen`.

  - Syntax:

    ```c
    int fclose(FILE *stream);
    ```

  - Description: 

    - `fclose` flushes any unwritten data from the output buffer (if the file was open for writing) & releases resources associated with the file stream.
    - After calling fclose, the file pointer (`FILE *`) becomes invalid and shouldn't be used again unless reinitialized with fopen.

  - Parameters:

    - `steam:` a pointer to a FILE object that was returned by fopen, freopen or tmpfile.

  - Return Value:

    - 0 --> success
    - EOF (-1) --> Error occurred (e.g: if the file wasn't opened  or closing failed)
    - You can use perror() or errno to get more info on the error.

  - Notes:

    - We call fclose when we're done with a file to avoid resource leaks and ensure that data is actually written.
    - Closing a file automatically flushes any buffers associated with it.

- Test Case: try closing the same file twice on an online compiler.

There's an issue in Picolibc where dynamic memory management functions, especially 'nano-malloc and 'nano-free' might overwrite some user data. An example of this is observed in the 'fclose' function in tinystdio. When calling 'fclose' which invokes bufio_close() then free() function with passing the file pointer passed to fclose at the beginning, the memory deallocation may affect the FILE structure.



This can result clearing 'unget' variable in case of 32-bit targets or 'unget' and 'flags' variables in case of 64-bit targets.

check whether it calls malloc or nano-malloc 
if it calls malloc, change the configuration in the meson build file.

fclose.c: try to use fclose() for the same file 2 times -> try it on an online compiler then 

check in C99 standard