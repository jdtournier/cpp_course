#include <iostream>
#include <algorithm>
#include <format>

#include "fragments.h"
#include "overlap.h"
#include "shotgun_sequencer.h"
#include "debug.h"


void ShotgunSequencer::init ()
{
  if (debug::verbose)
    fragment_statistics (m_fragments);
  m_sequence = extract_longest_fragment (m_fragments);
}




bool ShotgunSequencer::iterate ()
{
  debug::log ("---------------------------------------------------");
  debug::log (std::format ("{} fragments left", m_fragments.size()));

  auto overlap = find_biggest_overlap (m_sequence, m_fragments);

  // if no fragments found that overlap, or if largest overlap found is
  // less than 10, stop algorithm:
  if (overlap.fragment < 0 || std::abs (overlap.size) < m_minimum_overlap)
    return false;

  debug::log (
      std::format ("fragment with biggest overlap is at index {}, overlap = {}",
      overlap.fragment, overlap.size));

  merge (m_sequence, m_fragments[overlap.fragment], overlap.size);
  m_fragments.erase (m_fragments.begin() + overlap.fragment);

  return true;
}




void ShotgunSequencer::check_remaining_fragments ()
{
  debug::log (std::format (
        "{} fragments remaining unmatched - checking whether already contained in sequence...",
        m_fragments.size()));
  int num_unmatched = 0;
  for (auto& frag : m_fragments) {
    if (m_sequence.find (frag) == std::string::npos)
      ++num_unmatched;
  }

  if (num_unmatched)
    std::cerr << "WARNING: " << num_unmatched << " fragments remain unmatched!\n";
  else
    debug::log ("all remaining fragments matched OK");
}


