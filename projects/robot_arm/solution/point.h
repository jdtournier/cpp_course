#pragma once

#include <array>
#include <format>
#include <ostream>
#include <cmath>

using Point = std::array<double,3>;

inline std::ostream& operator<< (std::ostream& out, const Point& p)
{
  out << std::format ("[ {:.3f} {:.3f} {:.3f} ]", p[0], p[1], p[2]);
  return out;
}

inline Point operator- (const Point& a, const Point& b)
{
  return { a[0]-b[0], a[1]-b[1], a[2]-b[2] };
}

inline double length (const Point& x)
{
  return std::sqrt (x[0]*x[0] + x[1]*x[1] + x[2]*x[2]);
}

