#include <iostream>
#include <format>
#include <cmath>
#include <numbers>

#include "vector.h"

void Vector::print() const
{
  std::cout << std::format ("({}, {}) -> ({}, {})\n",
      m_start.get_x(), m_start.get_y(),
      m_end.get_x(), m_end.get_y());
}



float Vector::dot (const Vector& v2) const
{
    float x = m_end.get_x() - m_start.get_x();
    float y = m_end.get_y() - m_start.get_y();
    float x2 = v2.get_end().get_x() - v2.get_start().get_x();
    float y2 = v2.get_end().get_y() - v2.get_start().get_y();

    return x*x2 + y*y2;
}



float Vector::mag() const
{
    float x = m_end.get_x() - m_start.get_x();
    float y = m_end.get_y() - m_start.get_y();
    return std::sqrt(x * x + y * y);
}




float Vector::angle() const
{
    float x = m_end.get_x() - m_start.get_x();
    float y = m_end.get_y() - m_start.get_y();
    return std::atan2(y,x) * (180.0 / std::numbers::pi);
}


