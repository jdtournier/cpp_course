#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

#include "task.h"
#include "debug.h"

std::vector<int> load_task (const std::string& filename)
{
  debug::log ("loading task file \"" + filename + "\"...");
  std::vector<int> task;
  std::ifstream intask (filename);
  if (!intask)
    throw std::runtime_error ("error opening file \"" + filename + "\"");

  int val;
  while (intask >> val)
    task.push_back (val);

  debug::log ("task file \"" + filename + "\" loaded OK");
  return task;
}


std::vector<float> rescale (const std::vector<int>& task, int min, int max)
{
  std::vector<float> out (task.size());
  for (unsigned int n = 0; n < task.size(); ++n)
    out[n] = min + task[n] * (max-min);
  return out;
}

