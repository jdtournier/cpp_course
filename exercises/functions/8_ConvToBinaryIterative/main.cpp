#include <iostream>

#include "conv_bin.h"

// program to convert decimal to binary
int main ()
{
    int n;
    std::cout << "Enter decimal number (0 -255): ";
    std::cin >> n;
    conv_bin(n);
    return 0;
}
