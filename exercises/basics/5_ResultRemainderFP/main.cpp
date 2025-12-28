#include <iostream>

int main ()
{
    // Program to compute result
    // using floating-point arithmetic

    int n;
    float result;

    std::cout << "Enter a number: ";
    std::cin >> n;

    result = (2.0 + 3.0 * 3.0) / n;

    std::cout << "Result = " << result << "\n";

    return 0;
}

