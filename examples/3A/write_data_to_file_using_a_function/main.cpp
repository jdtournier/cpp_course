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


void write_data (const std::vector<int>& data, const std::string& filename)
{
  std::ofstream outfile (filename);
  if (!outfile) { // <- error checking is the same of for std::ifstream
    std::cerr << "ERROR: failed to open file \"" << filename << "\" for writing - aborting\n";
    return;
  }

  for (const auto& x : data)
    outfile << x << " ";
  outfile << "\n";
}



int main()
{
  std::string filename_in = "data.txt";
  std::string filename_out = "data_out.txt";

  auto data = load_data (filename_in);

  std::vector<int> pairwise_diff (data.size()-1);
  for (int n = 0; n < pairwise_diff.size(); n++)
    pairwise_diff[n] = data[n+1]-data[n];

  write_data (pairwise_diff, filename_out);

  return 0;
}
