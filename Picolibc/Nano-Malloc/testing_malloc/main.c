#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
	char name[20];
	int age;
};
int main()
{

	struct student* ptr = (struct student*)malloc(sizeof(struct student));
	strcpy(ptr->name, "Jana");
	ptr->age = 23;
	printf("Name = %s\n",ptr->name);
	free(ptr);
	printf("Name = %s\n", ptr->name);
	printf("Successfully freed struct in heap\n");
	exit(0);
	return 0;
}
