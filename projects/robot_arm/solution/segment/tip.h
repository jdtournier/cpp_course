#pragma once

#include "segment/base.h"

namespace Segment {

  class Tip : public Base {
    public:
      Tip (double length) :
        Base (nullptr, "tip"),
        m_length (length) { }

      Point tip_position () const override;

    private:
      const double m_length;
  };

}

