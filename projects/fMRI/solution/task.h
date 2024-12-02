#pragma once

#include <vector>
#include <string>

std::vector<int> load_task (const std::string& filename);

std::vector<float> rescale (const std::vector<int>& task, int min, int max);

