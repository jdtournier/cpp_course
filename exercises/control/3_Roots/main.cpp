#include <iostream>
#include <cmath>

int main ()
{
    // compute roots of quadratic equation of form ax^2 + bx + c = 0

    // declare variables for coefficients and roots
    float a, b, c, r1, r2;

    // read values of coefficients from user
    std::cout << "Enter a b c: ";
    std::cin >> a >> b >> c;

    // first check if roots are imaginary:
    float v = b * b - 4.0 * a * c;
    if (v < 0.0)
        std::cout << "roots are imaginary\n";
    else {
        // roots are real
        // compute roots
        r1 = ( -b + std::sqrt (v) ) / (2.0*a);
        r2 = ( -b - std::sqrt (v) ) / (2.0*a);

        // display answers
        std::cout << "Roots = " << r1 << ", " << r2 << "\n";
    }

    return 0;
}

