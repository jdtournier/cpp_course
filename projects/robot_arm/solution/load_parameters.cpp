#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <format>
#include <stdexcept>

#include "debug.h"
#include "load_parameters.h"

std::vector<std::vector<double>> load_parameters (const std::string& filename)
{
  debug::log ("loading parameters from file \"" + filename + "\"");

  std::ifstream in (filename);
  if (!in)
    throw std::runtime_error ("failed to open file \"" + filename + "\"");

  std::string line;
  std::vector<std::vector<double>> parameter_list;

  while (std::getline (in, line)) {
    std::vector<double> params;

    std::istringstream line_stream (line);
    double val;
    while (line_stream >> val)
      params.push_back (val);

    if (parameter_list.size() > 0)
      if (parameter_list[0].size() != params.size())
        throw std::runtime_error ("number of parameters differs between time points");

    parameter_list.push_back (params);
  }

  debug::log (
      std::format ("loaded {} parameters for {} time points",
        parameter_list[0].size(), parameter_list.size()));

  return parameter_list;
}
