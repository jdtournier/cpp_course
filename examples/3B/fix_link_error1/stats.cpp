#include <vector>

#include "stats.h"

double compute_mean (const std::vector<float>& data)
{
  double sum = 0.0;
  for (const auto x : data)
    sum += x;

  return sum / data.size();
}

