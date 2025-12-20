#include <iostream>
#include <cmath>

int main()
{
  double pi2_over_6 = 0.0;
  long int n = 1;

  while (1.0/(n*n) > 1.0e-15) {
    pi2_over_6 += 1.0/(n*n);
    n++;
  }

  std::cout << "\nValue of pi = " << std::sqrt(6.0*pi2_over_6) << " (computed in " << n << " iterations)\n";
  return 0;
}
