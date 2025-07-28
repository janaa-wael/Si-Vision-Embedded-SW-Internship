#include <stdio.h>
#include <stdlib.h>

extern int x;
char hello;
long long z = 10;
const int global_constant_var = 10;
static int static_global_initialized = 4;
static int static_glob_uninit = 5;
void func(void)
{
	static double static_local_init = 6;
	static float static_local_uninit = 7;
	int loc = 3;
	printf("Func is called\n");
}

int main()
{
	int y = 5;
	printf("Welcome to C!");
	printf("x = %d",x);
	return 0;
}
