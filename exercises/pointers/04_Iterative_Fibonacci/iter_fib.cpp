#include <iostream>

#include "iter_fib.h"

void fibonacci_iter (const int n)
{
    int fib[MAX_FIB];

    fib[0] = 0;
    fib[1] = 1;
    std::cout << fib[0] << " " << fib[1] << " ";

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
        std::cout << fib[i] << " ";
    }
    std::cout << "\n";
}
