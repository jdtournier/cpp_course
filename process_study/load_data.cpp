#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

#include "debug.h"
#include "load_data.h"
#include "treatment.h"

std::vector<std::vector<float>> load_study_data (const std::string& filename)
{
  debug::log ("loading file \"" + filename + "\"...");

  std::ifstream infile (filename);
  if (!infile)
    throw std::runtime_error ("failed to open file \"" + filename + "\" for reading");

  int n = 0;
  std::string line;
  std::vector<std::vector<float>> data;
  while (std::getline (infile, line)) {
    std::istringstream line_stream (line);

    std::string subject_ID;
    line_stream >> subject_ID;

    std::string treatment_group;
    line_stream >> treatment_group;

    // ignore blank lines:
    if (!line_stream)
      continue;

    std::vector<float> subj_data;
    float value;
    while (line_stream >> value)
      subj_data.push_back (value);

    if (subj_data.empty())
      throw std::runtime_error ("no data for subject \"" + subject_ID + "\"");

    data.push_back (subj_data);
  }

  if (data.empty())
    throw std::runtime_error ("file \"" + filename + "\" contains no usable data");

  debug::log ("found " + std::to_string(data.size()) + " subjects in file \"" + filename + "\"");

  return data;
}
