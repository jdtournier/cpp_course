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
