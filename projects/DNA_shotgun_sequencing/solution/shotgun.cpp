#include <iostream>
#include <string>
#include <stdexcept>
#include <format>

#include "fragments.h"
#include "overlap.h"
#include "debug.h"

int main (int argc, char* argv[])
{
  debug::set_verbose_mode (argc, argv);

  if (argc < 3) {
    std::cerr << "ERROR: missing arguments - expected 2 arguments: input_fragments output_sequence\n";
    return 1;
  }

  try { // Start of main processing:

    auto fragments = load_fragments (argv[1]);
    if (debug::verbose)
      fragment_statistics (fragments);

    auto sequence = extract_longest_fragment (fragments);
    std::cerr << "initial sequence has size " << sequence.size() << "\n";

    while (fragments.size()) {
      debug::log ("---------------------------------------------------");
      debug::log (std::to_string (fragments.size()) + " fragments left");

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

      debug::log (std::format ("fragment with biggest overlap is at index {}, overlap = {}",
            fragment_with_biggest_overlap, biggest_overlap));

      merge (sequence, fragments[fragment_with_biggest_overlap], biggest_overlap);
      fragments.erase (fragments.begin() + fragment_with_biggest_overlap);
    }

    debug::log (std::format ("{} fragments remaining unmatched - checking whether already contained in sequence...",
          fragments.size()));

    int num_unmatched = 0;
    for (const auto& frag : fragments) {
      if (sequence.find (frag) == std::string::npos)
        ++num_unmatched;
    }

    if (num_unmatched)
      std::cerr << "WARNING: " << num_unmatched << " fragments remain unmatched!\n";

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
