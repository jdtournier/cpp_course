#pragma once

#include <vector>

#include "types.h"

inline dtype pow2 (dtype x) { return x*x; }

// For the next two functions,  we return a double since dtype could be an
// integer type, and this would invalidate the calculation of both mean and
// std. dev.

double compute_mean (const std::vector<dtype>& data);
double compute_stddev (const std::vector<dtype>& data);
