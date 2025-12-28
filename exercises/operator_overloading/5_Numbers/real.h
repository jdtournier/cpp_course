#pragma once

#include "number.h"
#include <iostream>

class Real : public Number
{
    public:
        float get_n() const { return m_n; }
        void set_n(float val) { m_n = val; }
        void negate() { m_n = -m_n; }
        friend std::ostream& operator<< (std::ostream& os, const Real& r);
        friend std::istream& operator>> (std::istream& is, Real& r);
    protected:
        float m_n;
};

std::ostream& operator<< (std::ostream& os, const Real& r)
{
    os << r.m_n;
    return os;
}
std::istream& operator>> (std::istream& is, Real& r)
{
    is >> r.m_n;
    return is;
}