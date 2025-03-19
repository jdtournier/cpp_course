#pragma once

#include "segment/angle_base.h"

namespace Segment {

  class Rotate : public AngleBase {
    public:
      Rotate (double length) :
        AngleBase ("rotate"),
        m_length (length) { }

      Point tip_position () const override;

    private:
      const double m_length;
  };

}

