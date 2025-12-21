#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::vector<float>> load_patient_data (const std::string& filename)
{
  std::vector<std::vector<float>> data;

  std::ifstream infile (filename);
  if (!infile) {
    std::cerr << "ERROR: failed to open file \"" << filename << "\" for reading - aborting\n";
    return data;
  }

  int n = 0;
  std::string line;
  while (std::getline (infile, line)) {
    std::istringstream line_stream (line);

    std::string patient_ID;
    line_stream >> patient_ID;

    std::vector<float> pat_data;
    float value;
    while (line_stream >> value)
      pat_data.push_back (value);

    data.push_back (pat_data);
  }

  return data;
}


int main()
{
  std::string filename = "patient_data.txt";

  auto data = load_patient_data (filename);

  for (const auto& pat : data) {
    float sum = 0.0;
    for (const auto& value : pat)
      sum += value;
    std::cout << sum / pat.size() << "\n";
  }

  return 0;
}
