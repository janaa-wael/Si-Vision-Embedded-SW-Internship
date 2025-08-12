#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct employee{
	char name[20];
	int age;
};
int main()
{

	struct employee* ptr = (struct employee*)malloc(sizeof(struct employee));
	strcpy(ptr->name, "Jana");
	ptr->age = 23;
	printf("Name = %s\n",ptr->name);
	free(ptr);
	printf("Name = %s\n", ptr->name);
	printf("Successfully freed struct in heap\n");
	exit(0);
	return 0;
}
