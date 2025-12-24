#include <vector>
#include <cmath>

#include "types.h"
#include "stats.h"



double compute_mean (const std::vector<dtype>& data)
{
  double sum = 0.0;
  for (const auto& value : data)
    sum += value;
  return sum / data.size();
}



double compute_stddev (const std::vector<dtype>& data)
{
  const auto mean = compute_mean (data);
  double sum_diff = 0.0;
  for (const auto& value : data)
    sum_diff += pow2 (value-mean);
  return std::sqrt(sum_diff / (data.size()-1));
}
