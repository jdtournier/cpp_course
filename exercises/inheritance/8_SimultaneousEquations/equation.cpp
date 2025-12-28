#include "equation.h"

#include <iostream>

void SimultaneousEquations::solve() const
{
    float mult = m_e2.get_a() / m_e1.get_a();
    float y = (m_e2.get_c() - mult * m_e1.get_c()) / (m_e2.get_b() - mult * m_e1.get_b());
    float x = (m_e1.get_c() - m_e1.get_b() * y) / m_e1.get_a();
    std::cout << "Solution: x = " << x << ", y = " << y << std::endl;
}
