#include "segment/straight.h"

namespace Segment {

  Point Straight::tip_position () const
  {
    auto p = m_next.tip_position();
    return { p[0], p[1], m_length+p[2] };
  }

}
