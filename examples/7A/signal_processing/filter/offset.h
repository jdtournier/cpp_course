#pragma once

#include "filter/base.h"

class OffsetFilter : public GenericFilter {
  public:
    OffsetFilter (double offset) : GenericFilter ("offset"), m_offset (offset) { }

    double operator() (double s) { return s + m_offset; }

  private:
    const double m_offset;
};


