#pragma once

#include "segment/base.h"

namespace Segment {

  class Root : public Base {
    public:
      Root (Base& next) :
        Base (next, "root") { }

      Point tip_position () const override;
  };

}

