#include <iostream>
#include "Point.hpp"
using namespace std;

Point::Point()
: x(0), y(0)
{
    cout << "Default constructor is called." << endl;
}

Point::Point(int x, int y)
: x(x), y(y)
{
    cout << "Parameterized Constructor is called." << endl;
}

void Point::print()
{
    cout << "Point is at (" << x << "," << y << ") in the cartesian plane." << endl;
}


int main()
{
    Point p1;
    p1.print();
    Point p2(3,4);
    p2.print();
}