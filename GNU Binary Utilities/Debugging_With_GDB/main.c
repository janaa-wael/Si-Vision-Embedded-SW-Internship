#include <stdio.h>
#include <stdlib.h>

int global = 5;

void func2(int* x)
{
	(*x)++;
}

void func1()
{
	int x = 10;
	x++;
	x++;
	int y = 9;
	y--;
	y--;
	func2(&x);
}

void func3()
{
	global += 10;

}
int main()
{
	func1();
	func3();
	return 0;
}
