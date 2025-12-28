#include <iostream>
#include "matrix.h"
using namespace std;

int main() {
    Matrix x (2,2);
    x.Coef(0,0) = 1; x.Coef(0,1) = 2;
    x.Coef(1,0) = 3; x.Coef(1,1) = 4;

    Matrix y (2,2);
    y.Coef(0,0) = 2; y.Coef(0,1) = 3;
    y.Coef(1,0) = 4; y.Coef(1,1) = 5;

    Matrix z = x.Multiply(y);
    cout << "x:" << endl;
    x.Display();
    cout << "y:" << endl;
    y.Display();
    cout << "z:" << endl;
    z.Display();
    return 0;
}
