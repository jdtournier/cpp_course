#include <vector>
#include <cmath>

#include "stats.h"

float pow2 (float x)
{
  return x*x;
}


float compute_mean (const std::vector<float>& data)
{
  float sum = 0.0;
  for (const auto& value : data)
    sum += value;
  return sum / data.size();
}



float compute_stddev (const std::vector<float>& data)
{
  const float mean = compute_mean (data);
  float sum_diff = 0.0;
  for (const auto& value : data)
    sum_diff += pow2 (value-mean);
  return std::sqrt(sum_diff / (data.size()-1));
}
