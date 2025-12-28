#pragma once

#include "number.h"
#include "real.h"
#include <iostream>

class Complex : public Number
{
    public:
        Real get_r() const { return m_r; }
        void set_r(Real val) { m_r = val; }
        Real get_i() const { return m_i; }
        void set_i(Real val) { m_i = val; }
        void negate() { m_r.negate(); m_i.negate(); }
        void conjugate() { m_i.negate(); }
        friend std::ostream& operator<< (std::ostream& os, const Complex& c);
        friend std::istream& operator>> (std::istream& is, Complex& c);
    protected:
        Real m_r;
        Real m_i;
};

std::ostream& operator<< (std::ostream& os, const Complex& c)
{
    os << c.m_r << " + " << c.m_i << "i";
    return os;
}
std::istream& operator>> (std::istream& is, Complex& c)
{
    is >> c.m_r >> c.m_i;
    return is;
}
