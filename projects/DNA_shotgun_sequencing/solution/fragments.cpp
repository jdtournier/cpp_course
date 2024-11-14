#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

#include "fragments.h"

std::vector<std::string> load_fragments (const std::string& filename)
{
  std::cerr << "reading fragments from file \"" << filename << "\"...\n";

  std::ifstream infile (filename);
  if (!infile)
    throw std::runtime_error ("failed to open file \"" + filename + "\"");

  std::vector<std::string> fragments;
  std::string frag;
  while (infile >> frag)
    fragments.push_back (frag);

  if (fragments.empty())
    throw std::runtime_error ("file \"" + filename + "\" contains no fragments");

  std::cerr << "read " << fragments.size() << " fragments\n";

  return fragments;
}




void fragment_statistics (const std::vector<std::string>& fragments)
{
  double sum = 0.0;
  auto min = fragments[0].size();
  auto max = fragments[0].size();
  for (const auto& f : fragments) {
    sum += f.size();
    min = std::min (min, f.size());
    max = std::max (max, f.size());
  }
  std::cerr << "mean fragment length: " << sum/fragments.size() << ", range [ " << min << " " << max << " ]\n";
}




void write_sequence (const std::string& filename, const std::string& sequence)
{
  std::cerr << "writing sequence to file \"" << filename << "\"...\n";
  std::ofstream outfile (filename);
  if (!outfile)
    throw std::runtime_error ("failed to open output file \"" + filename + "\"");

  outfile << sequence << "\n";

  if (!outfile)
    throw std::runtime_error ("error occurred while writing to output file \"" + filename + "\"");
}

