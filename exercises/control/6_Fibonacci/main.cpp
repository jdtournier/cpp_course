#include <iostream>

int main ()
{
     int n1 = 0, n2 = 1;

     // print out the first two 1's
     std::cout << n1 << " " << n2 << " ";

    // loop until sum of two numbers is > 10000
    while ((n1 + n2) <= 10000) {
        // compute and print current Fibonacci number
        int current = n1 + n2;
        std::cout << current << " ";

        // remember most recent 2 numbers in series
        n1 = n2;
        n2 = current;
    }

    return 0;
}

