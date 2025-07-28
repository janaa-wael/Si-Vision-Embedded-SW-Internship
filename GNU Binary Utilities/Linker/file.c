#include <stdio.h>
#include <stdlib.h>

extern int x;
char hello;
long long z = 10;
const int global_constant_var = 10;
static int static_global_initialized = 4;
static int static_glob_uninit = 5;

int main()
{
	int y = 5;
	int result = func();
	printf("File main is running!\n");
	return 0;
}
