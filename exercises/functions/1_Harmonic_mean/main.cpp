#include <iostream>
#include "hmean.h"

int main ()
{
    float x, y;
    do {
        std::cout << "Enter two numbers (0 to quit): ";
        std::cin >> x >> y;
        if (((x != 0) && (y != 0)))
        std::cout << "Harmonic mean = " << harmonic_mean(x, y) << "\n";
    } while ((x != 0) && (y != 0));

    return 0;
}
