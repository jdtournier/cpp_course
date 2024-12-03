#include <numeric>
#include <cmath>
#include <stdexcept>

#include "utils.h"
#include "image.h"
#include "dataset.h"

double correlation_coefficient (const std::vector<int>& a, const std::vector<int>& b)
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



Image correlation_coefficient (const std::vector<int>& task, const Dataset& data)
{
  if (data.size() < 2)
    throw std::runtime_error ("dataset is too small to compute correlation coefficient!");
  if (data.size() != task.size())
    throw std::runtime_error ("number of time points in task doesn't match number in dataset");

  Image r (data[0].width(), data[0].height());

  for (int y = 0; y < data[0].height(); ++y)
    for (int x = 0; x < data[0].width(); ++x)
      r(x,y) = std::round (1000.0 * correlation_coefficient (task, data.get_timecourse (x,y)));

  return r;
}


