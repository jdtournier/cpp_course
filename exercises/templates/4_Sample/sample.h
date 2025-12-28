#pragma once

#include <iostream>
#include <cmath>

template<class t>
class Sample
{
    public:
        Sample() {m_n=0;};
        void set_sample(t val[], int n);
        float mean() const;
        float std_dev() const;
        void display() const;
        void sort();
    private:
        t m_x[100];
        int m_n;
};

template<class t>
void Sample<t>::set_sample(t val[], int n)
{
    m_n = n;
    for (int i = 0; i < m_n; i++)
        m_x[i] = val[i];
}

template<class t>
float Sample<t>::mean() const
{
    float sum = 0.0;
    for (int i = 0; i < m_n; i++) {
        sum = sum + m_x[i];
    }
    return sum/m_n;
}

template<class t>
float Sample<t>::std_dev() const
{
    float m = mean();
    float s = 0;
    for (int i = 0; i < m_n; i++) {
        s = s + (m_x[i] - m) * (m_x[i] - m);
    }
    s = sqrt(s / (m_n - 1));
    return s;
}

template<class t>
void Sample<t>::display() const
{
    using namespace std;
    for (int i = 0; i < m_n; i++)
        cout << m_x[i] << " ";
    std::cout << std::endl;
}

template<class t>
void Sample<t>::sort()
{
    float temp;

    //sort array using bubble sort algorithm
    for (int i = 0; i < m_n; i++) {
        for (int j = 0; j < m_n - 1; j++) {
            if (m_x[j] > m_x[j+1]) { // swap values
                temp = m_x[j];
                m_x[j] = m_x[j+1];
                m_x[j+1] = temp;
            }
        }
    }
}
