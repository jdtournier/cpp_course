#include "debug.h"
#include "segment/base.h"

namespace Segment {

  Base::~Base () {
    debug::log ("destroying segment of type " + m_type);
  }

}
