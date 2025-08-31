// test.c
#include <stdio.h>
int main() {
    int x = 10;
    int* ptr = &x;
    printf("Hello RISC-V 64!\n");
    printf("Size of pointer = %d\n",sizeof(ptr));
    return 0;
}

