#pragma once

#include <vector>
#include <array>

// Note that the implementation of std::vector is different for bool data type,
// which makes it difficult to use the operator() to set the values. Better to
// use a simple 'char' type here, which is an 8-bit integer anyway. We can use
// the value 0 & 1 for false & true respectively.

class Image {
  public:
    Image (int w, int h) : m_dim {w,h}, m_data (w*h, 0) { }
    int size(int axis) const { return m_dim[axis]; }
    char  operator() (int x, int y) const { return m_data[x+m_dim[0]*y]; }
    char& operator() (int x, int y)       { return m_data[x+m_dim[0]*y]; }
  private:
    std::array<int,2> m_dim;
    std::vector<char> m_data;
};


