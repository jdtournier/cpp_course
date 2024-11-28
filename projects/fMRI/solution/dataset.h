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
    const Image& get (int n) const { return m_slices[n]; }

    std::vector<int> get_timecourse (int x, int y) const;

  private:
    std::vector<Image> m_slices;
};

