#include <iostream>
#include "real.h"
#include "complex.h"
#include "rational.h"

int main()
{
    // read rational numbers
    Rational rat1, rat2;
    std::cout << "Enter first number (numerator denominator): " << std::endl;
    std::cin >> rat1;
    std::cout << "Enter second number (numerator denominator): " << std::endl;
    std::cin >> rat2;

    // multiplication
    std::cout << rat1 << " multiplied by " << rat2 << " = " << (rat1 * rat2) << std::endl;

    // division
    std::cout << rat1 << " divided by " << rat2 << " = " << (rat1 / rat2) << std::endl;

    // addition
    std::cout << rat1 << " added to " << rat2 << " = " << (rat1 + rat2) << std::endl;

    // subtraction
    std::cout << rat1 << " subtract " << rat2 << " = " << (rat1 - rat2) << std::endl;

    return 0;
}
