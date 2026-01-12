#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

#include "debug.h"
#include "load_data.h"
#include "patient.h"

PatientDataList load_patient_data (const std::string& filename)
{
  debug::log ("loading file \"" + filename + "\"...");

  std::ifstream infile (filename);
  if (!infile)
    throw std::runtime_error ("failed to open file \"" + filename + "\" for reading");

  int n = 0;
  std::string line;
  PatientDataList data;
  while (std::getline (infile, line)) {
    std::istringstream line_stream (line);

    std::string patient_ID;
    line_stream >> patient_ID;

    // ignore blank lines:
    if (!line_stream)
      continue;

    std::vector<dtype> pat_data;
    dtype value;
    while (line_stream >> value)
      pat_data.push_back (value);

    if (pat_data.empty())
      throw std::runtime_error ("no data for patient \"" + patient_ID + "\"");

    PatientData patient;
    patient.init (patient_ID, pat_data);
    data.push_back (patient);
  }

  if (data.empty())
    throw std::runtime_error ("file \"" + filename + "\" contains no usable data");

  debug::log ("found " + std::to_string(data.size()) + " patients in file \"" + filename + "\"");

  return data;
}
