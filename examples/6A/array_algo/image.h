#pragma once

#include <vector>
#include <array>
#include <format>
#include <ostream>

class Image {
  public:
    Image() = default;
    Image(const Image&) = default;
    Image (int w, int h) : m_data (w*h, 0), m_size { w, h } { }
    Image& operator= (const Image&) = default;

    int size (int axis) const { return m_size[axis]; }

    int& operator() (int i, int j) { return m_data[i+m_size[0]*j]; }
    const int& operator() (int i, int j) const { return m_data[i+m_size[0]*j]; }

  private:
    std::vector<int> m_data;
    std::array<int,2> m_size;
};



inline std::ostream& operator<< (std::ostream& stream, const Image& im)
{
  stream << im.size(0) << " x " << im.size(1) << " with contents\n";
  for (int j = 0; j < im.size(1); ++j) {
    for (int i = 0; i < im.size(0); ++i)
      stream << std::format ("{:5d} ", im(i,j));
    stream << "\n";
  }
  return stream;
}

