#pragma once

#include "segment/base.h"

namespace Segment {

  class Tip : public Base {
    public:
      Tip (double length) :
        Base (*this, "tip"),
        m_length (length) { }

      Point tip_position () const override {
        return { 0.0, 0.0, m_length };
      }

    private:
      const double m_length;
  };

}

