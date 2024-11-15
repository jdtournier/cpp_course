#include <iostream>
#include <string>
#include <stdexcept>

#include "fragments.h"
#include "overlap.h"

int main (int argc, char* argv[])
{
  if (argc < 3) {
    std::cerr << "ERROR: missing arguments - expected 2 arguments: input_fragments output_sequence\n";
    return 1;
  }

  try { // Start of main processing:

    auto fragments = load_fragments (argv[1]);
    fragment_statistics (fragments);

    auto sequence = extract_longest_fragment (fragments);
    std::cerr << "initial sequence has size " << sequence.size() << "\n";

    while (fragments.size()) {
      std::cerr << "---------------------------------------------------\n";
      std::cerr << fragments.size() << " fragments left\n";
      int biggest_overlap = 0;
      int fragment_with_biggest_overlap = -1;
      for (int n = 0; n < static_cast<int> (fragments.size()); ++n) {
        const auto overlap = compute_overlap (sequence, fragments[n]);
        if (std::abs (biggest_overlap) < std::abs (overlap)) {
          biggest_overlap = overlap;
          fragment_with_biggest_overlap = n;
        }
      }

      // if no fragments found that overlap, or if largest overlap found is
      // less than 10, stop algorithm:
      if (fragment_with_biggest_overlap < 0 || std::abs (biggest_overlap) < 10)
        break;

      std::cerr << "fragment with biggest overlap is at index " << fragment_with_biggest_overlap
        << ", overlap = " << biggest_overlap << "\n";

      merge (sequence, fragments[fragment_with_biggest_overlap], biggest_overlap);
      fragments.erase (fragments.begin() + fragment_with_biggest_overlap);
    }

    if (fragments.size())
      std::cerr << "WARNING: " << fragments.size() << " fragments remain unmatched!\n";

    std::cerr << "final sequence has length " << sequence.size() << "\n";
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
