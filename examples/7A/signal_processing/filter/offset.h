#pragma once

#include "filter/base.h"

class OffsetFilter : public GenericFilter {
  public:
    OffsetFilter (double offset) : GenericFilter ("offset"), m_offset (offset) { }

    std::string describe () const { return std::format ("{} (value: {})", m_name, m_offset); }

    double operator() (double s) { return s + m_offset; }

  private:
    const double m_offset;
};


