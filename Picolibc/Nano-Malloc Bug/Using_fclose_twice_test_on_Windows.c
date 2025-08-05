#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fp = fopen("test.txt", "w");
    if(fp == NULL)
    {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }
    fprintf(fp, "Hello, World!\n");
    int ret = fclose(fp);
    printf("fp = %p\n", (void*)fp);
    printf("Return value of fclose the 1st time: %d\n", ret);
    ret = fclose(fp);
    printf("Return value of fclose the 2nd time: %d\n",ret);

}