#pragma once

#include <algorithm>

#include "filter/base.h"

class ClampFilter : public GenericFilter {
  public:
    ClampFilter (double max) : GenericFilter ("clamp"), m_max (max) { }

    std::string describe () const { return std::format ("{} (max: {})", m_name, m_max); }

    double operator() (double s) {
      return std::max (std::min (s, m_max), -m_max);
    }

  private:
    const double m_max;
};

