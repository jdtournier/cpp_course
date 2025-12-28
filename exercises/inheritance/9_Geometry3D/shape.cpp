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

void Sphere::compute_volume()
{
   m_volume = 4 * M_PI * m_radius * m_radius * m_radius / 3.0;
}

void Sphere::compute_surface_area()
{
   m_surface_area = 4 * M_PI * m_radius * m_radius;
}

