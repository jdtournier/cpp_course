#include <iostream>
#include <vector>
#include <string>
#include <fstream>


std::vector<std::string> load_fragments (const std::string& filename)
{
  std::cerr << "reading fragments from file \"" << filename << "\"...\n";

  std::ifstream infile (filename);
  if (!infile) {
    std::cerr << "ERROR: failed to open file \"" << filename << "\" - aborting\n";
    std::exit (1);
  }

  std::vector<std::string> fragments;
  std::string frag;
  while (infile >> frag)
    fragments.push_back (frag);

  if (fragments.empty()) {
    std::cerr << "ERROR: file \"" << filename << "\" contains no fragments - aborting\n";
    std::exit (1);
  }

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
  if (!outfile) {
    std::cerr << "ERROR: failed to open output file \"" << filename << "\" - aborting\n";
    std::exit (1);
  }
  outfile << sequence << "\n";
  if (!outfile) {
    std::cerr << "ERROR: error occurred while writing to output file \"" << filename << "\" - aborting\n";
    std::exit (1);
  }
}





int main (int argc, char* argv[])
{
  if (argc < 3) {
    std::cerr << "ERROR: missing arguments - expected 2 arguments: input_fragments output_sequence\n";
    return 1;
  }

  auto fragments = load_fragments (argv[1]);
  fragment_statistics (fragments);


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

  write_sequence (argv[2], sequence);

  return 0;
}
