#pragma once

#include "fragments.h"

class ShotgunSequencer {
  public:
    ShotgunSequencer (int minimum_overlap = 10) :
      m_minimum_overlap (minimum_overlap) { }

    ShotgunSequencer (const std::vector<std::string>& fragments, int minimum_overlap = 10) :
      m_minimum_overlap (minimum_overlap) {
        init (fragments);
      }

    ShotgunSequencer (const std::string& fragments_filename, int minimum_overlap = 10) :
      ShotgunSequencer (load_fragments (fragments_filename), minimum_overlap) { }

    void load (const std::string& fragments_filename) {
      init (load_fragments (fragments_filename));
    }
    void save (const std::string& output_filename) const {
      write_sequence (output_filename, m_sequence);
    }

    void init (const std::vector<std::string>& fragments) {
      m_fragments = fragments;
      init();
    }
    void init ();

    bool iterate ();
    void check_remaining_fragments ();

    const std::vector<std::string>& remaining_fragments () const { return m_fragments; }
    const std::string& sequence () const { return m_sequence; }

  private:
    const int m_minimum_overlap;
    std::string m_sequence;
    std::vector<std::string> m_fragments;

    struct Overlap {
      int size;
      int fragment;
    };

    int compute_overlap (const std::string& fragment) const;
    Overlap find_biggest_overlap () const;
    void merge (const std::string& fragment, const int overlap);
};

