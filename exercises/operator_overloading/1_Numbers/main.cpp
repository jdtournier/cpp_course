#include <iostream>
#include "real.h"
#include "complex.h"
#include "rational.h"

int main()
{
    // rational numbers
    Rational rat1;
    rat1.set_n(1);
    rat1.set_d(2);
    std::cout << "Rational number 1: " << rat1 << std::endl;
    Rational rat2;
    rat2.set_n(4);
    rat2.set_d(5);
    std::cout << "Rational number 2: " << rat2 << std::endl;

    // multiply
    Rational rat3;
    rat3 = rat1 * rat2;
    std::cout << "Product: " << rat3 << std::endl;

    // increment
    //++rat3;
    std::cout << "Rational number 3: " << ++rat3 << std::endl;

    // division
    std::cout << rat1 << " divided by " << rat2 << " = " << (rat1 / rat2) << std::endl;

    // addition
    std::cout << rat1 << " added to " << rat2 << " = " << (rat1 + rat2) << std::endl;

    // subtraction
    std::cout << rat1 << " subtract " << rat2 << " = " << (rat1 - rat2) << std::endl;

    return 0;
}
