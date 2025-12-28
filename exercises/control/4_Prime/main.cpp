#include <iostream>

int main ()
{
    // loop through numbers from 1 to 50
    for (int i = 1; i <= 50; i++) {
        // is 'i' a prime number?
        bool isprime = true;
        for (int j = 2; j < i; j++) {
            if ((i % j) == 0) {
                isprime = false;
                // if we know it's not prime,
                // we can break straight away:
                break;
            }
        }
        if (isprime)
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}
