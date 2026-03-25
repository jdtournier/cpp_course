#pragma once

#include "filter/base.h"

class AverageFilter : public GenericFilter {
  public:
    AverageFilter (int width) :
      GenericFilter ("average"), m_buffer (width, 0.0), m_current (0) { }

    std::string describe () const { return std::format ("{} (width: {})", m_name, m_buffer.size()); }

    double operator() (double s)
    {
      // add value to buffer and update index for next round:
      m_buffer[m_current++] = s;
      m_current = m_current % m_buffer.size();

      // return average values in buffer:
      double sum = 0.0;
      for (auto x : m_buffer)
        sum += x;
      return sum / m_buffer.size();
    }

  private:
    std::vector<double> m_buffer;
    int m_current;
};

