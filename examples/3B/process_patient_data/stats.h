#pragma once

#include <vector>

inline float pow2 (float x) { return x*x; }

float compute_mean (const std::vector<float>& data);
float compute_stddev (const std::vector<float>& data);
