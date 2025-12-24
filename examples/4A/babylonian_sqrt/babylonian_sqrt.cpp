#include <iostream>
#include <cmath>

// This function computes the square root using the Babylonian method:
double babylonian_sqrt (const double value, int& niter)
{
  double x_current = value;   // <- the current estimate
  double x_prev = 0.0;        // <- the previous estimate

  niter = 0;
  while (std::abs (x_current-x_prev) > 1e-12) {
    x_prev = x_current;
    x_current = 0.5 * (x_prev + value/x_prev);
    niter++;
  }

  return x_current;
}


int main ()
{
  std::cout << "Enter a number: ";
  double x;
  std::cin >> x;

  int n;   // <- note we need to provide an integer to store the number of iterations!
  double val = babylonian_sqrt (x, n);
  std::cout << "Series evaluates to: " << val << " in " << n << " iterations\n";

  return 0;
}
