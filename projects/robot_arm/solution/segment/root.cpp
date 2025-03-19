#include "segment/root.h"

namespace Segment {

  Point Root::tip_position () const
  {
    return m_next->tip_position();
  }
}

