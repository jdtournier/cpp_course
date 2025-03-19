#include <cmath>

#include "segment/rotate.h"

namespace Segment {

  Point Rotate::tip_position () const
  {
    auto p = m_next->tip_position();
    const double s = std::sin (m_angle);
    const double c = std::cos (m_angle);
    return {
      c*p[0] - s*p[1],
      s*p[0] + c*p[1],
      m_length + p[2]
    };

  }
}

