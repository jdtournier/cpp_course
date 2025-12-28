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
        friend Complex operator* (const Complex& r1, const Complex& r2);
        friend Complex operator/ (const Complex& r1, const Complex& r2);
        friend Complex operator+ (const Complex& r1, const Complex& r2);
        friend Complex operator- (const Complex& r1, const Complex& r2);
        friend std::ostream& operator<< (std::ostream& os, const Complex& c);
        friend std::istream& operator>> (std::istream& is, Complex& c);
        Complex& operator++() // prefix increment - add 1 to real part
        {
            // increment
            ++m_r;

            // return the existing object
            return *this;
        }
    protected:
        Real m_r;
        Real m_i;
};

//overloaded multiplication operator
Complex operator* (const Complex& r1, const Complex& r2)
{
	Complex ret;
	ret.m_r = r1.m_r*r2.m_r - r1.m_i*r2.m_i;
	ret.m_i = r1.m_r*r2.m_i + r1.m_i*r2.m_r;
	return ret;
}

Complex operator/ (const Complex& r1, const Complex& r2)
{
    Complex ret, conj;
    conj = r2;
    conj.conjugate();
    ret = r1*conj;
    Real div = r2.m_r*r2.m_r + r2.m_i*r2.m_i;
    ret.m_r = ret.m_r/div;
    ret.m_i = ret.m_i/div;
	return ret;
}

Complex operator+ (const Complex& r1, const Complex& r2)
{
    Complex ret;
	ret.m_r = r1.m_r+r2.m_r;
	ret.m_i = r1.m_i+r2.m_i;
	return ret;
}

Complex operator- (const Complex& r1, const Complex& r2)
{
    Complex ret;
	ret.m_r = r1.m_r-r2.m_r;
	ret.m_i = r1.m_i-r2.m_i;
	return ret;
}

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