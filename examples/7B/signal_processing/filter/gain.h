#pragma once

#include <format>

#include "filter/base.h"

class GainFilter : public GenericFilter {
  public:
    GainFilter (double gain) : GenericFilter ("gain"), m_gain (gain) { }

    std::string describe () const { return std::format ("{} (factor: {})", m_name, m_gain); }

    double operator() (double s) { return s * m_gain; }

  private:
    const double m_gain;
};


