#pragma once

#include <string>

#include "point.h"

namespace Segment {

  class Base {
    public:
      Base (Base& next_segment, const std::string& type) :
        m_next (next_segment),
        m_type (type) { }

      const std::string& type () const { return m_type; }
      virtual Point tip_position () const { return m_next.tip_position(); }

    protected:
      Base& m_next;
      const std::string m_type;
  };

}
