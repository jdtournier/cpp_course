#include <iostream>

#include "sphere.h"

int main ()
{
    double r;
    do {
        std::cout << "Enter radius (type -ve number to stop): ";
        std::cin >> r;
        if (r < 0)
            break;
        auto m = sphere (r);
        std::cout << "V = " << m.vol << ", A = " << m.area << "\n";
    } while (r >= 0);
}
