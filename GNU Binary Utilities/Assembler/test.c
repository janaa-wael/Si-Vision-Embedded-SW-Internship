#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <string.h>

int main()
{
	char* endptr = NULL;
	errno = 0;
	double result = strtod("INFdfdg",&endptr);
	if(isinf(result))
	{
		printf("Result is infinity\n");
	}
	printf("errno = %.4d\n",errno);
	printf("output string: %s\n",endptr);

	if(*endptr == '\0')
	{
		printf("all characters are consumed\n");
	}
	else
	{
		printf("Remaining string: %s\n", endptr);
	}
	printf("ERANGE = %d", ERANGE);
	printf("HUGE_VAL = %.10f",HUGE_VAL);

}
