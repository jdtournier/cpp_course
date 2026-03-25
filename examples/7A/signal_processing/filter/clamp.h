#pragma once

#include <algorithm>

#include "filter/base.h"

class ClampFilter : public GenericFilter {
  public:
    ClampFilter (double max) : GenericFilter ("clamp"), m_max (max) { }

    double operator() (double s) {
      return std::max (std::min (s, m_max), -m_max);
    }

  private:
    const double m_max;
};

