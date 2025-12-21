#include <iostream>
#include <cmath>

const double pi = 3.141592653589793238462643;

double sinc (double x, double a)
{
  if (x == 0)
    return 1.0;
  float t = pi*x/a;
  return std::sin (t)/t;
}

int main ()
{
  double x = 0.1, a = 2.0;
  std::cout << "sinc (" << x << ") of width " << a << " = " << sinc (x,a) << "\n";

  return 0;
}
