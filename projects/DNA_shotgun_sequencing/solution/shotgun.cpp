#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int main (int argc, char* argv[])
{
  if (argc < 2) {
    std::cerr << "ERROR: expected filename as first argument\n";
    return 1;
  }
  std::cerr << "reading fragments from file \"" << argv[1] << "\"...\n";

  std::ifstream infile (argv[1]);
  if (!infile) {
    std::cerr << "ERROR: failed to open file \"" << argv[1] << "\" - aborting\n";
    return 1;
  }

  std::vector<std::string> fragments;
  std::string frag;
  while (infile >> frag)
    fragments.push_back (frag);

  if (fragments.empty()) {
    std::cerr << "ERROR: file \"" << argv[1] << "\" contains no fragments - aborting\n";
    return 1;
  }

  std::cerr << "read " << fragments.size() << " fragments\n";

  double sum = 0.0;
  auto min = fragments[0].size();
  auto max = fragments[0].size();
  for (const auto& f : fragments) {
    sum += f.size();
    min = std::min (min, f.size());
    max = std::max (max, f.size());
  }
  std::cerr << "mean fragment length: " << sum/fragments.size() << ", range [ " << min << " " << max << " ]\n";


  unsigned int size_of_longest = 0;
  unsigned int index_of_longest = 0;
  for (unsigned int n = 0; n < fragments.size(); ++n) {
    if (fragments[n].size() > size_of_longest) {
      index_of_longest = n;
      size_of_longest = fragments[n].size();
    }
  }
  std::string sequence = fragments[index_of_longest];
  std::cerr << "initial sequence has size " << sequence.size() << "\n";

  return 0;
}
