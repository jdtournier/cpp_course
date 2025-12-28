#pragma once
#include <iostream>
#include "number.h"

class Real : public Number
{
    public:
        float get_n() const { return m_n; }
        void set_n(float val) { m_n = val; }
        void negate() { m_n = -m_n; }
        void display() const { std::cout << m_n; }
    protected:
        float m_n;
};
