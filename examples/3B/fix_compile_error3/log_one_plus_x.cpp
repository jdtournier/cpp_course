#include <cmath>

#include "log_one_plus_x.h"

double log_one_plus_x (const double x, const int nelem)
{
  double value = 0.0;
  for (int n = 1; n <= nelem; n++)
    value += std::pow (-1, n+1) * std::pow (x, n) / n;
  return value;
}
