#pragma once

#include <iostream>
#include <cmath>

class Sample
{
    public:
        Sample() {m_n=0;};
        void set_sample(float val[], int n);
        float mean() const;
        float std_dev() const;
        void display() const;
        void sort();
    private:
        float m_x[100];
        int m_n;
};

void Sample::set_sample(float val[], int n)
{
    m_n = n;
    for (int i = 0; i < m_n; i++)
        m_x[i] = val[i];
}

float Sample::mean() const
{
    float sum = 0.0;
    for (int i = 0; i < m_n; i++) {
        sum = sum + m_x[i];
    }
    return sum/m_n;
}

float Sample::std_dev() const
{
    float m = mean();
    float s = 0;
    for (int i = 0; i < m_n; i++) {
        s = s + (m_x[i] - m) * (m_x[i] - m);
    }
    s = sqrt(s / (m_n - 1));
    return s;
}

void Sample::display() const
{
    using namespace std;
    for (int i = 0; i < m_n; i++)
        cout << m_x[i] << " ";
    cout << endl;
}

void Sample::sort()
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
