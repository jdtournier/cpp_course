#pragma once

#include <iostream>
#include <string>

class Binary: public Number
{
    public:
        Binary() {}
        Binary(int n)
        {
            int j = 0;
            for (int i = 128; i >= 1; i/=2) {
                if ((n / i) > 0) {
                    m_bits[j] = 1;
                    n -= i;
                }
                else
                    m_bits[j] = 0;
                j++;
            }
        }
        void negate() {
            for (int i = 0; i < 8; i++)
                m_bits[i] = !m_bits[i];
        }
        friend std::ostream& operator<< (std::ostream& os, const Binary& b);
        friend std::istream& operator>> (std::istream& is, Binary& b);
        friend Binary operator+ (const Binary& r1, const Binary& b2);
        friend Binary operator% (const Binary& b1, const Binary& b2);
        friend Binary operator|| (const Binary& b1, const Binary& b2);
        friend Binary operator&& (const Binary& b1, const Binary& b2);
        friend Binary operator!(const Binary& b);
        friend int operator==(const Binary& b1, const Binary& b2);
        Binary& operator= (const Binary &b) // overloaded assignment operator
        {
            // do the copy
            for (int i = 0; i < 8; i++)
                m_bits[i] = b.m_bits[i];

            // return the existing object
            return *this;
        }
        Binary& operator+=(const Binary& b)
        {
            bool carry = false;
            int v;
            for (int i = 7; i >= 0; i--) {
                v = this->m_bits[i] + b.m_bits[i] + carry; // Booleans can be cast to int (1=true, 0=false)
                this->m_bits[i] = (v % 2);
                carry = (v / 2);
            }
            if (carry)
                std::cerr << "Overflow warning in operator+" << std::endl;
            return *this;
        }
    protected:
        bool m_bits[8];
};

std::ostream& operator<< (std::ostream& os, const Binary& b)
{
    for (int i = 0; i < 8; i++)
        os << b.m_bits[i];
    return os;
}
std::istream& operator>> (std::istream& is, Binary& b)
{
    std::string s;
    char c;
    is >> s;
    for (int i = 0; i < 8; i++) {
        c = s[i];
        if (c == '1')
            b.m_bits[i] = true;
        else
            b.m_bits[i] = false;
    }
    return is;
}

Binary operator+ (const Binary& b1, const Binary& b2)
{
    Binary ret = b1;
    ret += b2;
    return ret;
}

Binary operator% (const Binary& b1, const Binary& b2)
{
    Binary ret;
    int v;
    for (int i = 7; i >= 0; i--) {
        v = b1.m_bits[i] + b2.m_bits[i]; // Booleans can be cast to int (1=true, 0=false)
        if (v == 1)
            ret.m_bits[i] = true;
        else
            ret.m_bits[i] = false;
    }
    return ret;
}

Binary operator|| (const Binary& b1, const Binary& b2)
{
    Binary ret;
    int v;
    for (int i = 7; i >= 0; i--) {
        v = b1.m_bits[i] + b2.m_bits[i]; // Booleans can be cast to int (1=true, 0=false)
        if (v > 0)
            ret.m_bits[i] = true;
        else
            ret.m_bits[i] = false;
    }
    return ret;
}

Binary operator&& (const Binary& b1, const Binary& b2)
{
    Binary ret;
    int v;
    for (int i = 7; i >= 0; i--) {
        v = b1.m_bits[i] + b2.m_bits[i]; // Booleans can be cast to int (1=true, 0=false)
        if (v == 2)
            ret.m_bits[i] = true;
        else
            ret.m_bits[i] = false;
    }
    return ret;
}

Binary operator!(const Binary& b)
{
    Binary ret;
    for (int i = 7; i >= 0; i--) {
        if (b.m_bits[i])
            ret.m_bits[i] = false;
        else
            ret.m_bits[i] = true;
    }
    return ret;
}

int operator==(const Binary& b1, const Binary& b2)
{
    int ret = 1; // true
    for (int i = 0; i < 8; i++) {
        if (b1.m_bits[i] != b2.m_bits[i])
            ret = 0; // false
    }
    return ret;
}