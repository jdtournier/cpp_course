#include "complex.h"
#include <iostream>
using namespace std;

void Complex::Display()
{
    cout << _r << " + " << _i << "i" << endl;
}


Complex Complex::Add(Complex c)
{
    Complex ret;
    ret.SetR(_r + c.GetR());
    ret.SetI(_i + c.GetI());
    return ret;
}


Complex Complex::Multiply(Complex n)
{
    float a = _r;
    float b = _i;
    float c = n.GetR();
    float d = n.GetI();
    Complex ret;
    ret.SetR(a*c - b*d);
    ret.SetI(a*d + b*c);
    return ret;
}
