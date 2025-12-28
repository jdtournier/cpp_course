#include <iostream>
#include "prime.h"

bool is_prime (int i)
{
    // special case: 1 is not prime
    if (i == 1)
        return false;

    for (int j = 2; j < i; j++)
        if ((i % j) == 0)
            return false;

    return true;
}


void display_primes (int n)
{
    std::cout << "prime numbers up to " << n << ": ";
    for (int i = 1; i <= n; i++) {
        if (is_prime(i))
            std::cout << i << " ";
    }
    std::cout << "\n";
}
