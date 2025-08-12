#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* fp = fopen("test.txt", "w);
	fprintf("Solving Bugs!");
	int ret = fclose(fp);
	printf("Return Value after fclose 1: %d", ret);
	printf("Return Value after fclose 2: %d", ret);
	ret = fclose(fp);
	return 0;
}
