#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITER 1000

int main(void) {
    clock_t start, end;
    start = clock();

    for (int i = 0; i < ITER; i++) {
        printf("Number: %d Hex: %08x String: %s Float: %f\n",
               i, i, "test", 3.14159);
    }

    end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Total time in tinystdio: %f seconds\n", time_taken);

    exit(0);
}

