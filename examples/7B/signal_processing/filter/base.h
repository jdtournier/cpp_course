#pragma once

#include <string>

class GenericFilter {
  public:
    GenericFilter (const std::string& name) : m_name (name) { }

    std::string describe () const { return m_name; }

    double operator() (double s) { return s; }

  protected:
    const std::string m_name;
};

