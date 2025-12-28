#include <iostream>

#include "conv_bin.h"

void conv_bin (int n)
{
    int res = n;
    for (int i = 128; i > 0; i /= 2) {
        std::cout << res / i;
        res = res % i;
    }
}

