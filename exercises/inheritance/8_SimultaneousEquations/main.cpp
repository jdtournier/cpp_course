#include <iostream>

#include "equation.h"

int main()
{
    SimultaneousEquations s;
    LinearEquation l1, l2;
    l1.set_coeffs(2.0, 1.0,7.0);
    l2.set_coeffs(3.0, -1.0, 8.0);
    s.set_equations(l1,l2);
    s.display();
    s.solve();
    return 0;
}
