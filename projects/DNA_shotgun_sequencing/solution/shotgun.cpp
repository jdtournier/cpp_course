#include <iostream>
#include <string>
#include <stdexcept>

#include "fragments.h"

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
