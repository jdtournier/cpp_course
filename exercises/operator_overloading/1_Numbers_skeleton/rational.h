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
        friend Rational operator* (const Rational& r1, const Rational& r2);
        friend std::ostream& operator<< (std::ostream& os, const Rational& r2);
        Rational& operator++() // prefix increment - add 1 to rational number
        {
            // increment
            m_n += m_d;

            // return the existing object
            return *this;
        }
        Rational& operator= (const Rational &r) // overloaded assignment operator
        {
            // do the copy
            m_d = r.m_d;
            m_n = r.m_n;

            // return the existing object
            return *this;
        }
    protected:
        int m_n;
        int m_d;
};

//overloaded multiplication operator
Rational operator* (const Rational& r1, const Rational& r2)
{
    Rational ret;
    int n = r1.m_n*r2.m_n;
    int d = r1.m_d*r2.m_d;
    ret.m_n = n;
    ret.m_d = d;
    return ret;
}

// overloaded output operator
std::ostream& operator<< (std::ostream& os, const Rational& r)
{
    os << r.m_n << "/" << r.m_d;
    return os;
}
