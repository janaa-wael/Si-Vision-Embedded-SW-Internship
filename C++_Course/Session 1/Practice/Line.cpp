#include <iostream>
#include "Line.hpp"

using namespace std;

Line::Line()
: p1(0,0), p2(0,0)
{

}
Line::Line(Point& p3, Point& p4)
: p1(p3), p2(p4)
{

}
    
void Line::setP1(Point& p1)
{
    this->p1 = p1;
}

void Line::setP2(Point& p2)
{
    this->p2 = p2;
}
int Line::calculateSlope()
{
    int deltaY = p1.getY() - p2.getY();
    int deltaX = p1.getX() - p2.getX();
    if(deltaX==0)
    {
        cout << "Slope is undefined (vertical line)." << endl;
        return 0;
    }
    else if(deltaY == 0)
    {
        cout << "Slope is zero. (horizontal line)." << endl;
        return 0;
    }
    else
    {
        return deltaY/deltaX;
    }
}

int Line::calculateY_Intercept(void)
{
    return (p1.getY() - calculateSlope()*p1.getX());
}
void Line::print()
{
    cout << "Line implements: y = " << calculateSlope() << "x + " << calculateY_Intercept() << endl;
}