#include <iostream>
#include <cmath>  // <= error 1: missing include to use std::sqrt()

int main ()
{
    // compute roots of quadratic equation of form ax^2 + bx + c = 0

    // declare variables for coefficients and roots
    float a, b, c, r1, r2;

    // read values of coefficients from user
    std::cout << "Enter a b c: ";
    std::cin >> a >> b >> c;   // <= error 2: wrong direction for operator

    // compute roots
    r1 = ( -b + std::sqrt (b*b - 4.0*a*c) ) / (2.0*a);
    r2 = ( -b - std::sqrt (b*b - 4.0*a*c) ) / (2.0*a);
    // ^ error 3: use brackets to ensure correct order of operations

    // display answers
    std::cout << "Roots = " << r1 << ", " << r2 << "\n";
    return 0;
}


