
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main()
{
  std::string filename = "patient_data.txt";

  std::ifstream infile (filename);
  if (!infile) {
    std::cerr << "ERROR: failed to open file \"" << filename << "\" for reading - aborting\n";
    return 1;
  }

  int n = 0;
  std::string line;
  while (std::getline (infile, line)) {
    std::istringstream line_stream (line);

    std::string patient_ID;
    line_stream >> patient_ID;

    float val, measurement_count = 0;
    while (line_stream >> val)
      measurement_count++;

    std::cout << "line " << n++ << ": patient ID \"" << patient_ID << "\" has " << measurement_count << " measurements\n";
  }

  return 0;
}
