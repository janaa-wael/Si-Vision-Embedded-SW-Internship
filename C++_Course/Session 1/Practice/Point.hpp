#include <iostream>

using namespace std;


class Point {
    private:
        int x;
        int y;
    public:
        Point();
        Point(int x, int y);
        void print();
        void setX(int x);
        void setY(int y);
        int getX() const;
        int getY() const;
};