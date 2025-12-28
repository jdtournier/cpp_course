#include <iostream>
#include "real.h"
#include "complex.h"
#include "rational.h"
#include "binary.h"

int main()
{
    // read real numbers
    Binary b1, b2, b3;
    std::cout << "Enter first binary number: ";
    std::cin >> b1;
    std::cout << "Enter second binary number: ";
    std::cin >> b2;

    // display
    std::cout << "First number: " << b1 << std::endl;
    std::cout << "Second number: " << b2 << std::endl;

    // assignment
    b3 = b2;
    std::cout << " Assignment: " << b3 << std::endl;

    return 0;
}
