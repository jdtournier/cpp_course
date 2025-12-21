#include <iostream>
#include <cmath>

const double pi = 3.141592653589793238462643;

int main()
{
  float x;
  std::cout << "Enter value of x: ";
  std::cin >> x;

  std::cout << "result: " << std::sqrt(2.0*pi / std::abs(x)) * std::exp (2.0*std::pow (std::sin (0.1*x), 2)) << "\n";

  return 0;
}
