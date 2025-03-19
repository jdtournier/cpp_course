#pragma once

#include "segment/base.h"

namespace Segment {

  class Straight : public Base {
    public:
      Straight (double length) :
        Base ("straight"),
        m_length (length) { }

      Point tip_position () const override;

    private:
      const double m_length;
  };

}

