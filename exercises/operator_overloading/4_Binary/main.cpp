#include <iostream>
#include "binary.h"

int main()
{
    Binary b1, b2;
    std::cout << "Enter binary number 1: ";
    std::cin >> b1;
    std::cout << "Enter binary number 2: ";
    std::cin >> b2;
    std::cout << "Binary number 1: " << b1 << std::endl;
    std::cout << "Binary number 2: " << b2 << std::endl;
    std::cout << b1 << " + " << b2 << " = " << (b1 + b2) << std::endl;
    std::cout << b1 << " XOR " << b2 << " = " << (b1 % b2) << std::endl;
    std::cout << b1 << " OR " << b2 << " = " << (b1 || b2) << std::endl;
    std::cout << b1 << " AND " << b2 << " = " << (b1 && b2) << std::endl;
    std::cout << "NOT " << b1 << " = " << !b1 << std::endl;
    return 0;
}
