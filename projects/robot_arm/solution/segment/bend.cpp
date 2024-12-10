#include <cmath>

#include "segment/bend.h"

namespace Segment {

  Point Bend::tip_position () const
  {
    auto p = m_next.tip_position();
    const double s = std::sin (m_angle);
    const double c = std::cos (m_angle);
    return {
      s*(m_length/2.0 + p[2]) + c*p[0],
      p[1],
      m_length/2.0 + c*(m_length/2.0 + p[2]) - s*p[0]
    };

  }
}

