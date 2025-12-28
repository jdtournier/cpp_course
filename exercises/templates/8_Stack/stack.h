#pragma once

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
    m_data[m_n++] = val;
}

template<class t, int nmax>
t Stack<t, nmax>::pop()
{
    return m_data[--m_n];
}
