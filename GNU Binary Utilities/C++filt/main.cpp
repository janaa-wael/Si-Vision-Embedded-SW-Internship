#include <iostream>
using namespace std;

int func1(int x, double y)
{
    return x + y;
}

long long fun2(long long x, float y)
{
    return x + y;
}

int main()
{ 
	cout << "FUnc1 return value = " << func1(4, 5.6) << endl;
	cout << "Func2 return value = " << fun2(445634654LL, 345.4f) << endl;
	cout << "Hello, World!"<< endl;
}

