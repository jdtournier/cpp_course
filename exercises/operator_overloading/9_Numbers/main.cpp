#include <iostream>
#include "real.h"
#include "complex.h"
#include "rational.h"
#include "binary.h"

int main()
{
    // read real numbers
    Real r1, r2;
    std::cout << "Enter first real number: ";
    std::cin >> r1;
    std::cout << "Enter second real number: ";
    std::cin >> r2;

    // display
    std::cout << "First number: " << r1 << std::endl;
    std::cout << "Second number: " << r2 << std::endl;

    // comparison
    if (r1 == r2)
        std::cout << "Comparison: true" << std::endl;
    else
        std::cout << "Comparison: false" << std::endl;

    // read binary numbers
    Binary b1, b2;
    std::cout << "Enter first binary number: ";
    std::cin >> b1;
    std::cout << "Enter second binary number: ";
    std::cin >> b2;

    // display
    std::cout << "First number: " << b1 << std::endl;
    std::cout << "Second number: " << b2 << std::endl;

    // comparison
    if (b1 == b2)
        std::cout << "Comparison: true" << std::endl;
    else
        std::cout << "Comparison: false" << std::endl;
    return 0;
}
