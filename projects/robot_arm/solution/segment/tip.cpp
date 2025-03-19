#include <stdexcept>

#include "segment/tip.h"

namespace Segment {

  Point Tip::tip_position () const {
    return { 0.0, 0.0, m_length };
  }

  void Tip::set_angle (int n, double angle) {
    throw std::runtime_error ("attempt to set angle beyond end of arm!");
  }

}
