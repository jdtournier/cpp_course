#include <iostream>
#include "real.h"
#include "complex.h"
#include "rational.h"
#include "binary.h"

int main()
{
    // read rational numbers
    Rational rat1, rat2;
    std::cout << "Enter first rational number (numerator denominator): ";
    std::cin >> rat1;
    std::cout << "Enter second rational number (numerator denominator): ";
    std::cin >> rat2;

    // multiplication
    std::cout << rat1 << " multiplied by " << rat2 << " = " << (rat1 * rat2) << std::endl;

    // division
    std::cout << rat1 << " divided by " << rat2 << " = " << (rat1 / rat2) << std::endl;

    // addition
    std::cout << rat1 << " added to " << rat2 << " = " << (rat1 + rat2) << std::endl;

    // subtraction
    std::cout << rat1 << " subtract " << rat2 << " = " << (rat1 - rat2) << std::endl;

    // read complex numbers
    Complex c1, c2;
    std::cout << "Enter first complex number (real imaginary): ";
    std::cin >> c1;
    std::cout << "Enter second complex number (real imaginary): ";
    std::cin >> c2;

   // display
    std::cout << "First number: " << c1 << std::endl;
    std::cout << "Second number: " << c2 << std::endl;

    // read real numbers
    Real r1, r2;
    std::cout << "Enter first real number: ";
    std::cin >> r1;
    std::cout << "Enter second real number: ";
    std::cin >> r2;

   // display
    std::cout << "First number: " << r1 << std::endl;
    std::cout << "Second number: " << r2 << std::endl;

    // read binary numbers
    Binary b1, b2;
    std::cout << "Enter binary number 1: ";
    std::cin >> b1;
    std::cout << "Enter binary number 2: ";
    std::cin >> b2;

   // display
    std::cout << "Binary number 1: " << b1 << std::endl;
    std::cout << "Binary number 2: " << b2 << std::endl;

    return 0;
}
