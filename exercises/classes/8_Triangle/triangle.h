#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"

class Triangle
{
    public:
        Triangle() {};
        Triangle(Point p1, Point p2, Point p3) {_p1 = p1; _p2 = p2; _p3 = p3;};
        Point Getp1() const { return _p1; }
        void Setp1(Point val) { _p1 = val; }
        Point Getp2() const { return _p2; }
        void Setp2(Point val) { _p2 = val; }
        Point Getp3() const { return _p3; }
        void Setp3(Point val) { _p3 = val; }
        float Area();
    private:
        Point _p1;
        Point _p2;
        Point _p3;
};

#endif // TRIANGLE_H
