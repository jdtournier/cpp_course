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

  return 0;
}
