#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* fp = fopen("test.txt", "w");
	int ret = fclose(fp);
	printf("Return Value after fclose 1: %d\n", ret);
	ret = fclose(fp);
	printf("Return Value after fclose 2: %d\n", ret);
	exit(0);
	return 0;
}

