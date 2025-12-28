#pragma once

#include <iostream>
#include <string>

class Binary
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
        friend std::ostream& operator<< (std::ostream& os, const Binary& b);
        friend std::istream& operator>> (std::istream& is, Binary& b);
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
