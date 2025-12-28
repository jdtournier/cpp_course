#pragma once

#include <iostream>

#include "number.h"

class Rational : public Number
{
    public:
        int get_n() const { return m_n; }
        void set_n(int val) { m_n = val; }
        int get_d() const { return m_d; }
        void set_d(int val) { m_d = val; }
        void negate() { m_n = -m_n; }
        void display() const { std::cout << m_n << " / " << m_d; }
    protected:
        int m_n;
        int m_d;
};
