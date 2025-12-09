#include <iostream>
#include <cmath>

// define a struct to hold the return values:
struct SqrtResult { double value; int niter; };

// This function computes the square root using the Babylonian method:
SqrtResult babylonian_sqrt (const double value)   // <- function now returns the struct
{                                         // ^ no need to pass niter by reference
  double x_current = value;   // <- the current estimate
  double x_prev = 0.0;        // <- the previous estimate

  int niter = 0;
  while (std::abs (x_current-x_prev) > 1e-12) {
    x_prev = x_current;
    x_current = 0.5 * (x_prev + value/x_prev);
    niter++;
  }

  return { x_current, niter };   // <- return the result using aggregate initialisation
}


int main ()
{
  std::cout << "Enter a number: ";
  double x;
  std::cin >> x;

  auto res = babylonian_sqrt (x);    // <- function now takes a single argument
  std::cout << "Series evaluates to: " << res.value << " in " << res.niter << " iterations\n";

  return 0;
}
