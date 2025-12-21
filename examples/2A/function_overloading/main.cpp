#include <iostream>
#include <cmath>

double log_one_plus_x (const double x)
{
  double value = 0.0;
  for (int n = 1; n <= 10; n++)
    value += std::pow (-1, n+1) * std::pow (x, n) / n;
  return value;
}


double log_one_plus_x (const double x, const int nelem)
{
  double value = 0.0;
  for (int n = 1; n <= nelem; n++)
    value += std::pow (-1, n+1) * std::pow (x, n) / n;
  return value;
}


int main ()
{
  const double x = 0.1;
  std::cout << "log (1+" << x << ") = " << log_one_plus_x(x) << "\n";

  std::cout << "------------------------\n";
  std::cout << "log (1+" << x << ") for different numbers of elements:\n";
  for (int n = 1; n < 10; n++)
    std::cout << n << " elements: value = " << log_one_plus_x(x, n) << "\n";

  return 0;
}
