#include <iostream>
#include <vector>
#include <string>
#include <fstream>


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





int main (int argc, char* argv[])
{
  if (argc < 3) {
    std::cerr << "ERROR: missing arguments - expected 2 arguments: input_fragments output_sequence\n";
    return 1;
  }

  try { // Start of main processing:

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

  } // end of main processing

  // error handling from here:
  catch (std::exception& excp) {
    std::cerr << "ERROR: " << excp.what() << " - aborting\n";
    return 1;
  }
  catch (...) {
    std::cerr << "ERROR: unknown exception thrown - aborting\n";
    return 1;
  }

  return 0;
}
