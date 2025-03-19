#pragma once

#include <string>

#include "point.h"
#include "debug.h"

namespace Segment {

  class Base {
    public:
      Base (Base* next_segment, const std::string& type) :
        m_next (next_segment),
        m_type (type) {
          debug::log ("constructing segment of type " + m_type);
        }

      virtual ~Base();

      const std::string& type () const { return m_type; }
      virtual Point tip_position () const = 0;

    protected:
      Base* m_next;
      const std::string m_type;
  };

}
