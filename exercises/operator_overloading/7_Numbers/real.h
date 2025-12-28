#pragma once

#include <iostream>
#include "number.h"

class Real : public Number
{
    public:
        float get_n() const { return m_n; }
        void set_n(float val) { m_n = val; }
        void negate() { m_n = -m_n; }
        friend Real operator* (const Real& r1, const Real& r2);
        friend Real operator/ (const Real& r1, const Real& r2);
        friend Real operator+ (const Real& r1, const Real& r2);
        friend Real operator- (const Real& r1, const Real& r2);
        friend std::ostream& operator<< (std::ostream& os, const Real& r);
        friend std::istream& operator>> (std::istream& is, Real& r);
        Real& operator++() // prefix increment - add 1
        {
            // increment
            m_n = m_n + 1;

            // return the existing object
            return *this;
        }
    protected:
        float m_n;
};
//overloaded multiplication operator
Real operator* (const Real& r1, const Real& r2)
{
	Real ret;
	ret.m_n = r1.m_n*r2.m_n;
	return ret;
}

Real operator/ (const Real& r1, const Real& r2)
{
    Real ret;
	ret.m_n = r1.m_n/r2.m_n;
	return ret;
}

Real operator+ (const Real& r1, const Real& r2)
{
    Real ret;
	ret.m_n = r1.m_n+r2.m_n;
	return ret;
}

Real operator- (const Real& r1, const Real& r2)
{
    Real ret;
	ret.m_n = r1.m_n-r2.m_n;
	return ret;
}

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