#include <stdio.h>
#include <stdlib.h>

void func1(int x, int y)
{
	printf("x = %d, y = %d",x,y);
	return;
}

int var1 = 1;

int main()
{
	int var2 = 10;
	printf("Hello, strip command!");
	func1(3,5);

}
