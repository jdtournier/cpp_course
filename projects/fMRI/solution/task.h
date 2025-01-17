#pragma once

#include <vector>
#include <string>

std::vector<int> load_task (const std::string& filename);

template <typename ValueType>
std::vector<float> rescale (const std::vector<ValueType>& task, ValueType min, ValueType max)
{
  std::vector<float> out (task.size());
  for (unsigned int n = 0; n < task.size(); ++n)
    out[n] = min + task[n] * (max-min);
  return out;
}



