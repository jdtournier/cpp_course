#pragma once

#include <array>
#include <format>
#include <ostream>

using Point = std::array<double,3>;

inline std::ostream& operator<< (std::ostream& out, const Point& p)
{
  out << std::format ("[ {:.3f} {:.3f} {:.3f} ]", p[0], p[1], p[2]);
  return out;
}

