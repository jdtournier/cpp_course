#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> load_data (const std::string& filename)
{
  std::vector<int> data;

  std::ifstream infile (filename);
  if (!infile) {
    std::cerr << "ERROR: failed to open file \"" << filename << "\" for reading - aborting\n";
    return data;
  }

  int n;
  while (infile >> n)
    data.push_back (n);

  return data;
}



int main()
{
  std::string filename_in = "data.txt";
  std::string filename_out = "data_out.txt";

  auto data = load_data (filename_in);

  std::ofstream outfile (filename_out);
  if (!outfile) { // <- error checking is the same of for std::ifstream
    std::cerr << "ERROR: failed to open file \"" << filename_out << "\" for writing - aborting\n";
    return 1;
  }

  for (int n = 0; n < data.size()-1; n++)
    outfile << data[n+1]-data[n] << " ";
  outfile << "\n";

  return 0;
}
