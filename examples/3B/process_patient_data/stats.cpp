#include <vector>

#include "stats.h"

float compute_mean (const std::vector<float>& data)
{
  float sum = 0.0;
  for (const auto& value : data)
    sum += value;
  return sum / data.size();
}
