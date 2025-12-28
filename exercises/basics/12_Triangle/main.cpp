#include <iostream>
#include <cmath>

int main ()
{
    float a, b, c;
    std::cout << "Enter the values of a b c: ";
    std::cin >> a >> b >> c;

    float s = (a + b + c) / 2.0;
    float area = std::sqrt (s * (s - a) * (s - b) * (s - c));

    std::cout << "The area of the triangle is " << area << "\n";
    return 0;
}

