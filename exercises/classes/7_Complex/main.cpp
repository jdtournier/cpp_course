#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
    Complex c1;
    c1.SetR(2); c1.SetI(3.5);
    Complex c2;
    c2.SetR(4.3); c2.SetI(-0.5);
    c1.Display();
    c2.Display();
    Complex c3 = c1.Add(c2);
    c3.Display();
    Complex c4 = c1.Multiply(c2);
    c4.Display();
    return 0;
}
