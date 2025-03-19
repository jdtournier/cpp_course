#pragma once

#include "segment/base.h"

namespace Segment {

  class Straight : public Base {
    public:
      Straight (Base* next, double length) :
        Base (next, "straight"),
        m_length (length) { }

      Point tip_position () const override;

    private:
      const double m_length;
  };

}

