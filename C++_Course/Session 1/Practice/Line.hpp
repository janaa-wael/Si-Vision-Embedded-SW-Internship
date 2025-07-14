#include <iostream>
#include "Point.hpp"
using namespace std;

class Line
{
private: 
    Point p1;
    Point p2;
public:
    Line();
    Line(Point& p3, Point& p4);
    void setP1(Point& p1);
    void setP2(Point& p2);
    void print();
    int calculateY_Intercept(void);
    int calculateSlope(void);
};