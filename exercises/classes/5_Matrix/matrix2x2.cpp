#include <iostream>
#include <format>

#include "matrix2x2.h"

void Matrix2x2::display()
{
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            std::cout << std::format("{:8} ", coef(i,j));
        std::cout << "\n";
    }
}

Matrix2x2 Matrix2x2::multiply (Matrix2x2 m)
{
    Matrix2x2 r;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            r.set_coef (i, j, coef(i,0) * m.coef(0,j) + coef(i,1) * m.coef(1,j));
    return r;
}
