#pragma once

#include "segment/angle_base.h"

namespace Segment {

  class Bend : public AngleBase {
    public:
      Bend (double length) :
        AngleBase ("bend"),
        m_length (length) { }

      Point tip_position () const override;

    private:
      const double m_length;
  };

}

