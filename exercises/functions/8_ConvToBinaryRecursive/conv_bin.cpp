#include <iostream>

#include "conv_bin.h"

void conv_bin (int n, int unit)
{
    if (unit > 128)
        return;

    conv_bin (n/2, unit*2);
    std::cout << n%2;
}
