#include "segment/angle_base.h"

namespace Segment {

  void AngleBase::set_angle (int n, double angle) {
    if (n == 0)  m_angle = angle;
    else m_next->set_angle (n-1, angle);
  }

}
