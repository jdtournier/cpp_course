#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

#include "debug.h"
#include "load_data.h"

std::vector<std::vector<float>> load_patient_data (const std::string& filename)
{
  log ("loading file \"" + filename + "\"...");

  std::ifstream infile (filename);
  if (!infile)
    throw std::runtime_error ("failed to open file \"" + filename + "\" for reading");

  int n = 0;
  std::string line;
  std::vector<std::vector<float>> data;
  while (std::getline (infile, line)) {
    std::istringstream line_stream (line);

    std::string patient_ID;
    line_stream >> patient_ID;

    // ignore blank lines:
    if (!line_stream)
      continue;

    std::vector<float> pat_data;
    float value;
    while (line_stream >> value)
      pat_data.push_back (value);

    if (pat_data.empty())
      throw std::runtime_error ("no data for patient \"" + patient_ID + "\"");

    data.push_back (pat_data);
  }

  if (data.empty())
    throw std::runtime_error ("file \"" + filename + "\" contains no usable data");

  log ("found " + std::to_string(data.size()) + " patients in file \"" + filename + "\"");

  return data;
}
