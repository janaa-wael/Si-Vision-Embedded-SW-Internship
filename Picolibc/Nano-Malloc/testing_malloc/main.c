#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* ptr = (int*)malloc(4);
	printf("Successfully allocated 4 bytes in heap\n");
	*ptr = 23;
	free(ptr);
	printf("Successfully freed 4 bytes in heap\n");
	exit(0);
	return 0;
}
