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
        float s_e() const;
        float lower_95() const;
        float upper_95() const;
        float median();
        float iqr();
        float skew();
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
float Sample<t>::s_e() const
{
    float s = std_dev();
    return (s / sqrt(m_n));
}

template<class t>
float Sample<t>::lower_95() const
{
    float mn = mean();
    float se = s_e();
    return (mn - 1.96 * se);
}

template<class t>
float Sample<t>::upper_95() const
{
    float mn = mean();
    float se = s_e();
    return (mn + 1.96 * se);
}

template<class t>
float Sample<t>::median()
{
    // sort and take middle value
    sort();
    if (((m_n + 1) % 2) == 0) // odd sample size
        return m_x[m_n/2];
    else // even sample size - return mean of middle 2 elements
        return ((m_x[(m_n + 1) / 2] + m_x[(m_n + 1) / 2 - 1]) / 2.0);
}

template<class t>
float Sample<t>::iqr()
{
    float lowerQ, upperQ;

    // sort and take middle value
    sort();
    if (((m_n + 1) % 4) == 0) { // can take single value as lower Q
        lowerQ = m_x[(m_n + 1) / 4];
        upperQ = m_x[3 * (m_n + 1) / 4];
    } else { // even sample size
        lowerQ = (m_x[(m_n + 1) / 4] + m_x[(m_n + 1) / 4 - 1]) / 2.0;
        upperQ = (m_x[3 * (m_n + 1) / 4] + m_x[3 * (m_n + 1) / 4 - 1]) / 2.0;
    }

    return (upperQ - lowerQ);
}

template<class t>
float Sample<t>::skew()
{
    float mn = mean();
    float md = median();
    float sd = std_dev();
    return (3 * (mn - md) / sd);
}

template<class t>
void Sample<t>::display() const
{
    for (int i = 0; i < m_n; i++)
        std::cout << m_x[i] << " ";
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
