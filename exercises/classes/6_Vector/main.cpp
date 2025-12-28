#include <iostream>

#include "vector.h"

int main()
{
    Point p1 (0,0);
    Point p2 (3,2);
    Point p3 (2,4);

    Vector v1 (p1,p2);
    std::cout << "v1: ";
    v1.print();
    std::cout << "|v1| = " << v1.mag() << "\n";
    std::cout << "Ang(v1) = " << v1.angle() << "\n";

    Vector v2 (p1,p3);
    std::cout << "v2: ";
    v2.print();
    std::cout << "v1 . v2 = " << v1.dot (v2) << "\n";

    return 0;
}

