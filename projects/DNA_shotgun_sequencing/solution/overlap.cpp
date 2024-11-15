#include <iostream>
#include <stdexcept>
#include <string>

#include "overlap.h"
#include "fragments.h"

int compute_overlap (const std::string& sequence, const std::string& fragment)
{
  if (fragment.size() > sequence.size())
    throw std::runtime_error ("fragment size larger than current sequence - this shouldn't happen!");

  std::cerr << "------------------------------------------------------\n";
  std::cerr << "sequence is \"" << sequence << "\"\n";
  std::cerr << "trying fragment \"" << fragment << "\"\n";

  // Start from the largest overlap, and decrease size of overlap at each
  // iteration. This guarantees we stop as soon as we find the largest overlap:
  for (int overlap = fragment.size(); overlap > 0; --overlap) {
    const auto seq_start = sequence.substr(0, overlap);
    const auto frag_end = fragment.substr(fragment.size()-overlap);
    //std::cerr << "  overlap = " << overlap << ": seq " << seq_start << ", fragment " << frag_end << "\n";
    if (seq_start == frag_end)
      return overlap;
  }

  return 0;
}

