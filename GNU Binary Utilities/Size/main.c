#include <stdio.h>
#include <stdlib.h>


int glob_uninit;
int glob_init = 10;

static int static_glob_init = 11;
static int static_glob_uninit ;

int main()
{
	static char  static_lcl_init = 13;
	static char static_lcl_uninit ;
	printf("This program is used to text the size of memory sections!\n");
}
