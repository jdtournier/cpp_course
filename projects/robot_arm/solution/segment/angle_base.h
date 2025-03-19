#pragma once

#include "segment/base.h"

namespace Segment {

  class AngleBase : public Base {
    public:
      AngleBase (const std::string& type) :
        Base (type),
        m_angle (0.0) { }

      virtual ~AngleBase () { }

      void set_angle (int n, double angle) override;

    protected:
      double m_angle;
  };

}


