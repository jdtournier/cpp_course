#include <iostream>
#include <cmath>

#include "matrix.h"
#include "image.h"
#include "algo.h"


inline float func (float x) { return std::exp(2.0*x-1); }


int main ()
{
  Matrix3x3 M ({ 0.1, 0.2, 0.3 },
               { 0.4, 0.5, 0.6 },
               { 0.7, 0.8, 0.9 });

  std::cout << "M = \n" << M << "\n";

  Image P (5, 10);
  for (int j = 0; j < P.size(1); ++j)
    for (int i = 0; i < P.size(0); ++i)
      P(i,j) = i+P.size(1)-j;

  std::cout << "image =\n" << P << "\n";

  std::cout << "mean of M = " << get_mean (M) << "\n";
  std::cout << "mean of P = " << get_mean (P) << "\n";

  std::cout << "transpose of M:\n" << transpose (M) << "\n";
  std::cout << "transpose of P:\n" << transpose (P) << "\n";

  for_each (M, func);
  std::cout << "M = \n" << M << "\n";

  return 0;
}
