#pragma once

#include <vector>

#include "image.h"
#include "dataset.h"

double correlation_coefficient (const std::vector<int>& a, const std::vector<int>& b);

Image correlation_coefficient (const std::vector<int>& task, const Dataset& data);

