#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x = 1;
	FILE* f1 = fopen("test.txt","rw");
	printf("F1 =  %p\n",f1);
	//FILE* f2 = f1;
	//FILE* f3= &x;
	int ret = fclose(f1);
	FILE* f2 = fopen("test1.txt","w");
	printf("F2 =  %p\n",f2);
	ret= fclose(f1);
	printf("Return of file 1 fclose %d\n",ret);	
	exit(0);
	return 0;
}
