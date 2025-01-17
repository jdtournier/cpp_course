#pragma once

#include <vector>
#include <numeric>

#include "image.h"
#include "dataset.h"


template <typename VectorType1, typename VectorType2>
double correlation_coefficient (const VectorType1& a, const VectorType2& b)
{
  if (a.size() != b.size())
    throw std::runtime_error ("size mismatch for vectors in correlation_coefficient()");

  const double mean_a = std::accumulate (a.begin(), a.end(), 0.0) / a.size();
  const double mean_b = std::accumulate (b.begin(), b.end(), 0.0) / b.size();

  double numerator = 0.0;
  double sos_a = 0.0, sos_b = 0.0;

  for (unsigned int n = 0; n < a.size(); ++n) {
    const double diff_a = a[n] - mean_a;
    const double diff_b = b[n] - mean_b;
    numerator += diff_a * diff_b;
    sos_a += diff_a * diff_a;
    sos_b += diff_b * diff_b;
  }

  return numerator / ( std::sqrt(sos_a) * std::sqrt(sos_b) );
}


Image correlation_coefficient (const std::vector<int>& task, const Dataset& data);


