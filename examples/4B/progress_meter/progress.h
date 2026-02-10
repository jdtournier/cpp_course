#pragma once

#include <iostream>
#include <string>
#include <format>

class ProgressBar {
  public:
    ProgressBar (const std::string& message, int max_count) :
      m_text (message), m_max (max_count), m_count (0) { }

    ~ProgressBar () {
      std::cerr << std::format ("\r[done] {}\n", m_text);
    }

    void inc () {
      m_count++;
      int percentage = ((100*m_count) / m_max);
      std::cerr << std::format("\r[{:3d}%] {}...", percentage, m_text);
    }

  private:
    const std::string m_text;
    const int m_max;
    int m_count;
};

