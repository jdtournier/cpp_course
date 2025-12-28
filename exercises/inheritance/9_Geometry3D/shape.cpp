#include <cmath>
#include "shape.h"

void Circle::compute_area()
// implementation of virtual function from Shape
{
    m_area = M_PI * m_radius * m_radius;
}

void Circle::compute_perimeter()
// implementation of virtual function from Shape
{
    m_perimeter = 2.0 * M_PI * m_radius;
}

void Square::compute_area()
// implementation of virtual function from Shape
{
    m_area = m_side * m_side;
}

void Square::compute_perimeter()
// implementation of virtual function from Shape
{
    m_perimeter = 4.0 * m_side;
}
