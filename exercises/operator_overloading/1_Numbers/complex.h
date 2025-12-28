#pragma once

#include <iostream>
#include "number.h"
#include "real.h"

class Complex : public Number
{
    public:
        Real get_r() const { return m_r; }
        void set_r(Real val) { m_r = val; }
        Real get_i() const { return m_i; }
        void set_i(Real val) { m_i = val; }
        void negate() { m_r.negate(); m_i.negate(); }
        void conjugate() { m_i.negate(); }
        void display() const {m_r.display(); std::cout << " + "; m_i.display(); std::cout << "i";}
    protected:
        Real m_r;
        Real m_i;
};
