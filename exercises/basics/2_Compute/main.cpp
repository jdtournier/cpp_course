#include <iostream>

int main ()
{
    // Program to compute result of expression
    // (a):
    std::cout << "Value = " << (7.0 * 3) / 5 << "\n";
    // answer: 4.2

    // (b):
    std::cout << "Value = " << (7 * 3) / 5 << "\n";
    // answer: 4

    // (c):
    std::cout << "Value = " << (7 * 3) % 5 << "\n";
    // answer: 1

    // (d):
    // std::cout << "Value = " << (7.0 * 3) % 5 << endl;
    // will not compile: modulo operator undefined
    // for floating point types!

    return 0;
}

