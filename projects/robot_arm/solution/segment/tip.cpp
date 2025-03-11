#include "segment/tip.h"

namespace Segment {

  Point Tip::tip_position () const {
    return { 0.0, 0.0, m_length };
  }

}
