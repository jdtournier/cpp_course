#include <cmath>
#include "triangle.h"

float Triangle::Area()
{
    float a = sqrt ((_p1.GetY() - _p2.GetY()) * (_p1.GetY() - _p2.GetY()) +
            (_p1.GetX() - _p2.GetX()) * (_p1.GetX() - _p2.GetX()));
    float b = sqrt ((_p1.GetY() - _p3.GetY()) * (_p1.GetY() - _p3.GetY()) +
            (_p1.GetX() - _p3.GetX()) * (_p1.GetX() - _p3.GetX()));
    float c = sqrt ((_p2.GetY() - _p3.GetY()) * (_p2.GetY() - _p3.GetY()) +
            (_p2.GetX() - _p3.GetX()) * (_p2.GetX() - _p3.GetX()));
    if (((a + b) > c) && ((a + c) > b) && ((b + c) > a)) { // valid
        float s = 0.5 * (a + b + c);
        float area = sqrt (s * (s - a) * (s - b) * (s - c));
        return area;
    }
    else // not valid
        return -1;
}
