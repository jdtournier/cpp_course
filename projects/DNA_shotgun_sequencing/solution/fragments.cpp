#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

#include "debug.h"
#include "fragments.h"

std::vector<std::string> load_fragments (const std::string& filename)
{
  if (debug::verbose)
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

  if (debug::verbose)
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
  std::cerr << fragments.size() << " fragments, mean fragment length: " << sum/fragments.size() << ", range [ " << min << " " << max << " ]\n";
}




void write_sequence (const std::string& filename, const std::string& sequence)
{
  if (debug::verbose)
    std::cerr << "writing sequence to file \"" << filename << "\"...\n";

  std::ofstream outfile (filename);
  if (!outfile)
    throw std::runtime_error ("failed to open output file \"" + filename + "\"");

  outfile << sequence << "\n";

  if (!outfile)
    throw std::runtime_error ("error occurred while writing to output file \"" + filename + "\"");
}




std::string extract_longest_fragment (std::vector<std::string>& fragments)
{
  unsigned int size_of_longest = 0;
  unsigned int index_of_longest = 0;

  for (unsigned int n = 0; n < fragments.size(); ++n) {
    if (fragments[n].size() > size_of_longest) {
      index_of_longest = n;
      size_of_longest = fragments[n].size();
    }
  }

  std::string longest_fragment = fragments[index_of_longest];
  fragments.erase (fragments.begin()+index_of_longest);

  return longest_fragment;
}
