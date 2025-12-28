#include <iostream>
#include "real.h"
#include "complex.h"
#include "rational.h"
#include "binary.h"

int main()
{
    // read binary numbers
    Binary b1, b2;
    std::cout << "Enter first binary number: ";
    std::cin >> b1;
    std::cout << "Enter second binary number: ";
    std::cin >> b2;

    // +=
    std::cout << b1 << " += " << b2 << std::endl;
    b1 += b2;
    std::cout << b1 << std::endl;

    // read real numbers
    Real r1, r2;
    std::cout << "Enter first real number: ";
    std::cin >> r1;
    std::cout << "Enter second real number: ";
    std::cin >> r2;

    // +=
    std::cout << r1 << " += " << r2 << std::endl;
    r1 += r2;
    std::cout << r1 << std::endl;

    // read complex numbers
    Complex c1, c2;
    std::cout << "Enter first complex number (real imag): ";
    std::cin >> c1;
    std::cout << "Enter second complex number (real imag): ";
    std::cin >> c2;

    // +=
    std::cout << c1 << " += " << c2 << std::endl;
    c1 += c2;
    std::cout << c1 << std::endl;

    // read rational numbers
    Rational rat1, rat2;
    std::cout << "Enter first rational number (numerator denominator): ";
    std::cin >> rat1;
    std::cout << "Enter second rational number (numerator denominator): ";
    std::cin >> rat2;

    // +=
    std::cout << rat1 << " += " << rat2 << std::endl;
    rat1 += rat2;
    std::cout << rat1 << std::endl;

    return 0;
}
