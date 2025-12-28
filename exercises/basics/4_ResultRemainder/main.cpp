#include <iostream>

int main ()
{
    // Program to compute result and remainder
    // using integer arithmetic

    int n, result , remainder;

    std::cout << "Enter a number: ";
    std::cin >> n;

    result = (2 + 3 * 3) / n;
    remainder = (2 + 3 * 3) % n;

    std::cout << "Result = " << result << "\n";
    std::cout << "Remainder = " << remainder << "\n";

    return 0;
}

