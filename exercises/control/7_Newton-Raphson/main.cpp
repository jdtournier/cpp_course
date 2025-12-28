#include <iostream>
#include <cmath>

int main ()
{
    // newton -raphson approximation
    float epsilon;

    // successive approximation
    float x1 = 2.9; // first guess

    do {
        // evaluate function
        float y1 = cos(x1) - x1;

        // compute derivative at x1:
        float y1deriv = -sin(x1) - 1.0;

        // new best guess:
        float x2 = x1 - y1 / y1deriv;

        // error:
        epsilon = std::abs(x2 - x1);

        // update best guess:
        x1 = x2;
    } while (epsilon > 0.001);

    // display result:
    std::cout << "Best guess = " << x1 << "\n";

    return 0;
}
