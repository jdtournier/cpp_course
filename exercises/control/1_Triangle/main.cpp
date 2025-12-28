#include <iostream>
#include <cmath>
#include <stdexcept>

int main ()
{
    float a, b, c;
    std::cout << "Enter the values of a b c: ";
    std::cin >> a >> b >> c;

    // check:
    if (((a + b) <= c) || ((a + c) <= b) || ((b + c) <= a))
      throw std::runtime_error ("Not a valid triangle");

    float s = (a + b + c) / 2.0;
    float area = std::sqrt (s * (s - a) * (s - b) * (s - c));

    std::cout << "The area of the triangle is " << area << "\n";
    return 0;
}

