#pragma once

#include "fragments.h"

class ShotgunSequencer {
  public:
    void init (const std::vector<std::string>& fragments);
    bool iterate ();
    void check_remaining_fragments ();

    const std::vector<std::string>& remaining_fragments () const { return m_fragments; }
    const std::string& sequence () const { return m_sequence; }

  private:
    const int m_minimum_overlap = 10;
    std::string m_sequence;
    std::vector<std::string> m_fragments;
};

