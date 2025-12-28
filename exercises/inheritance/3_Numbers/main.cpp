#include <iostream>

#include "real.h"
#include "complex.h"
#include "rational.h"

int main()
{
    // real number
    Real r;
    r.set_n(2.3);
    r.display(); std::cout << std::endl;
    r.negate();
    r.display(); std::cout << std::endl;

    // rational number
    Rational rat;
    rat.set_n(17);
    rat.set_d(23);
    rat.display(); std::cout << std::endl;
    rat.negate();
    rat.display(); std::cout << std::endl;

    // complex number
    Real r2; r2.set_n(7.6);
    Real r3; r3.set_n(3.9);
    Complex c;
    c.set_r(r2);
    c.set_i(r3);
    c.display(); std::cout << std::endl;
    c.negate();
    c.display(); std::cout << std::endl;
    c.conjugate();
    c.display(); std::cout << std::endl;

    return 0;
}
