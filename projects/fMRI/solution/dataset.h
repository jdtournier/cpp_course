#pragma once

#include <vector>
#include <string>

#include "image.h"

class Dataset
{
  public:
    Dataset () = default;
    Dataset (const std::vector<std::string>& filenames) { load (filenames); }

    void load (const std::vector<std::string>& filenames);

    unsigned int size () const { return m_slices.size(); }

    Image<int>&       operator[] (int n)       { return m_slices[n]; }
    const Image<int>& operator[] (int n) const { return m_slices[n]; }

    std::vector<int> get_timecourse (int x, int y) const;

  private:
    std::vector<Image<int>> m_slices;
};


inline std::ostream& operator<< (std::ostream& out, const Dataset& data)
{
  out << "Data set with " << data.size() << " images:\n";
  for (unsigned int n = 0; n < data.size(); ++n)
    out << "  image " << n << ": " << data[n] << "\n";
  return out;
}
