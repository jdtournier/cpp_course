#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>

#include "array.h"


std::vector<float> load_array (const std::string& filename)
{
  std::ifstream infile (filename);
  if (!infile)
    throw std::runtime_error ("failed to open file \"" + filename + "\" for reading");

  std::vector<float> data;
  float value;
  while (infile >> value)
      data.push_back (value);

  if (data.empty())
    throw std::runtime_error ("file \"" + filename + "\" contains no usable data");

  return data;
}



void save_array (const std::string& filename, const std::vector<float>& data)
{
  std::ofstream outfile (filename);
  if (!outfile)
    throw std::runtime_error ("failed to open file \"" + filename + "\" for writing");

  for (const auto x : data)
    outfile << x << " ";
  outfile << "\n";
}



std::vector<float> add_arrays (const std::vector<float>& v1, const std::vector<float>& v2)
{
  if (v1.size() != v2.size())
    throw std::runtime_error ("add_arrays(): cannot add arrays of different sizes");

  std::vector<float> out (v1.size());
  for (int n = 0; n < v1.size(); n++)
    out[n] = v1[n] + v2[n];

  return out;
}


