#include <iostream>
#include <cmath>

int main()
{
  double xp, x = 1.0;
  int niter = 0;

  do {
    xp = x;
    x = std::sqrt (7*xp-1);
    niter++;
  } while (std::abs(x-xp) > 1.0e-12);

  std::cout << "\nValue of x = " << x << " (computed in " << niter << " iterations)\n";
  std::cout << "Verify: x² - 7x + 1 = " << x*x - 7.0*x + 1.0 << "\n";
  return 0;
}
