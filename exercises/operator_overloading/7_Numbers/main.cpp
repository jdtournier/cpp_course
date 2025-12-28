#include <iostream>
#include "real.h"
#include "complex.h"
#include "rational.h"
#include "binary.h"

int main()
{
    // read real numbers
    Real r1, r2;
    std::cout << "Enter first real number): ";
    std::cin >> r1;
    std::cout << "Enter second real number: ";
    std::cin >> r2;

    // display
    std::cout << "First number: " << r1 << std::endl;
    std::cout << "Second number: " << r2 << std::endl;

    // increment
    Real r3 = r1;
    ++r3;
    std::cout << r1 << " incremented = " << r3 << std::endl;

    // addition
    std::cout << r1 << " + " << r2 << " = " << r1+r2 << std::endl;

    // subtraction
    std::cout << r1 << " - " << r2 << " = " << r1-r2 << std::endl;

    // multiplication
    std::cout << r1 << " * " << r2 << " = " << r1*r2 << std::endl;

    // division
    std::cout << r1 << " / " << r2 << " = " << r1/r2 << std::endl;

    return 0;
}
