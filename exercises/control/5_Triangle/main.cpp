#include <iostream>
#include <cmath>

int main ()
{
    char response = 'y';

    // loop whilst user wants to compute more areas:
    do {
        float a, b, c;
        std::cout << "Enter the values of a b c: ";
        std::cin >> a >> b >> c;

        // check:
        if (((a + b) <= c) || ((a + c) <= b) || ((b + c) <= a))
          std::cout << "Not a valid triangle\n";
        else {
            float s = (a + b + c) / 2.0;
            float area = std::sqrt (s * (s - a) * (s - b) * (s - c));

            std::cout << "The area of the triangle is " << area << "\n";
        }

        // do another one?
        std::cout << "Continue (y/n)? ";
        std::cin >> response;
    } while (response == 'y' || response == 'Y');

    return 0;
}

