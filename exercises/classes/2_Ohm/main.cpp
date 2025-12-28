#include <iostream>

#include "resistor.h"

int main()
{
    float omega = 3.0;
    Resistor r;
    r.set_R(omega);
    std::cout << "Omega = " << omega << "\n";
    std::cout << "I for 6V = " << r.get_I(6) << "\n";
    std::cout << "V for 2A = " << r.get_V(2) << "\n";
    std::cout << "W for 2A = " << r.power(2) << "\n";

    return 0;
}
