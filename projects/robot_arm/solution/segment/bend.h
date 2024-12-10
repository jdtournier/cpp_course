#pragma once

#include "segment/base.h"

namespace Segment {

  class Bend : public Base {
    public:
      Bend (Base& next, double length) :
        Base (next, "bend"),
        m_length (length),
        m_angle (0.0) { }

      Point tip_position () const override;

      void set_angle (double angle) { m_angle = angle; }

    private:
      const double m_length;
      double m_angle;
  };

}

