#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x = 1;
	FILE* f1 = fopen("test1.txt","r");
	printf("F1 =  %p\n",f1);
	int ret = fclose(f1);
	printf("Return of file 1 fclose %d\n",ret);
	FILE* f2 = fopen("test1.txt","r");
	printf("F2 =  %p\n",f2);
	ret= fclose(f2);
	printf("Return of file 2 fclose %d\n",ret);	
	exit(0);
	return 0;
}
