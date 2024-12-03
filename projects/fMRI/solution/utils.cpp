#include <cmath>
#include <stdexcept>

#include "utils.h"
#include "image.h"
#include "dataset.h"


Image<float> correlation_coefficient (const std::vector<int>& task, const Dataset& data)
{
  if (data.size() < 2)
    throw std::runtime_error ("dataset is too small to compute correlation coefficient!");
  if (data.size() != task.size())
    throw std::runtime_error ("number of time points in task doesn't match number in dataset");

  Image<float> r (data[0].width(), data[0].height());

  for (int y = 0; y < data[0].height(); ++y)
    for (int x = 0; x < data[0].width(); ++x)
      r(x,y) = correlation_coefficient (task, data.get_timecourse (x,y));

  return r;
}


