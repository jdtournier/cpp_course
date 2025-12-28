#pragma once

#include <iostream>

template<class t, int nmax>
class Stack
{
    public:
        Stack() { m_n = 0; }
        void push(t val);
        t pop();
    private:
        t m_data[nmax];
        int m_n;
};

template<class t, int nmax>
void Stack<t, nmax>::push(t val)
{
    if (m_n >= nmax)
        std::cerr << "Warning, stack size exceeded, not pushing element " << val << std::endl;
    else
        m_data[m_n++] = val;
}

template<class t, int nmax>
t Stack<t, nmax>::pop()
{
    if (m_n <= 0) {
        std::cerr << "Warning, can't pop from empty stack - return value undefined" << std::endl;
        return m_data[0];
    }
    else
        return m_data[--m_n];
}
