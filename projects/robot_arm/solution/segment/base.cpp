#include "debug.h"
#include "segment/base.h"

namespace Segment {

  Base::~Base () {
    debug::log ("destroying segment of type " + m_type);
  }

  void Base::set_angle (int n, double angle)
  {
    m_next->set_angle (n, angle);
  }

}
