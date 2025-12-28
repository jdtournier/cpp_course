#include <iostream>
#include <iomanip>

#include "matrix.h"

using namespace std;

void Matrix::Display()
{
    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < cols(); j++) {
            cout << setw(8) << Coef(i,j) << "  ";
        }
        cout << endl;
    }
}

Matrix Matrix::Multiply (const Matrix& b)
{
    if (cols() != b.rows())
        throw "dimension mismatch!";

    Matrix ret (rows(), b.cols());
    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < b.cols(); j++) {
            double x = 0.0;
            for (int k = 0; k < cols(); k++)
                x += Coef (i,k) * b.Coef (k,j);
            ret.Coef (i,j) = x;
        }
    }
    return ret;
}
