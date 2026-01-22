#pragma once

#include <vector>
#include <cmath>


template <typename T> inline T pow2 (T x) { return x*x; }

// For the next two functions,  we return a double since T could be an
// integer type, and this would invalidate the calculation of both mean and
// std. dev.

template <typename T> double compute_mean (const std::vector<T>& data)
{
  double sum = 0.0;
  for (const auto& value : data)
    sum += value;
  return sum / data.size();
}



template <typename T> double compute_stddev (const std::vector<T>& data)
{
  const auto mean = compute_mean (data);
  double sum_diff = 0.0;
  for (const auto& value : data)
    sum_diff += pow2 (value-mean);
  return std::sqrt(sum_diff / (data.size()-1));
}
