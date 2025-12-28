#include <iostream>
#include <cmath>
#include <vector>

#include "sample.h"

void Sample::set_sample (const std::vector<float>& vals)
{
  m_data = vals;
}


float Sample::mean() const
{
    float sum = 0.0;
    for (unsigned int i = 0; i < m_data.size(); i++) {
        sum = sum + m_data[i];
    }
    return sum/m_data.size();
}


float Sample::std_dev() const
{
    float m = mean();
    float s = 0.0;
    for (unsigned int i = 0; i < m_data.size(); i++)
        s = s + (m_data[i] - m) * (m_data[i] - m);
    s = std::sqrt (s / (m_data.size() - 1));

    return s;
}


void Sample::display() const
{
    std::cout << "[ ";
    for (auto v : m_data)
        std::cout << v << " ";
    std::cout << "]\n";
}
