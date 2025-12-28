#include <iostream>

#include "matrix2x2.h"

int main()
{
    Matrix2x2 x (1,2,3,4);
    Matrix2x2 y (2,3,4,5);
    Matrix2x2 z = x.multiply(y);

    std::cout << "x:\n";
    x.display();

    std::cout << "y:\n";
    y.display();

    std::cout << "z:\n";
    z.display();

    return 0;
}
