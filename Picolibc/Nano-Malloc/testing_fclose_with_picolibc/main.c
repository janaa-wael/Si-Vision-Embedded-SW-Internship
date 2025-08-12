#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Open a temporary file in write mode
    FILE *fp = tmpfile();
    if (!fp) {
        perror("tmpfile");
        return 1;
    }

    // Trigger some unget buffer usage
    ungetc('A', fp);  // Set unget to 'A'

    printf("Before fclose: unget=%d\n", fp->unget);

    // Closing will call fclose() -> bufio_close() -> free(fp)
    fclose(fp);

    // Now fp is freed — dereferencing is technically UB,
    // but for testing, we check if 'unget' was overwritten
    printf("After fclose: unget=%d (should still be 'A' if not overwritten)\n", fp->unget);

    return 0;
}

