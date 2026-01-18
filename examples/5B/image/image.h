#pragma once

#include <vector>
#include <ostream>

class Image {
  public:
    Image() = default;
    Image(const Image&) = default;
    Image (int w, int h) : m_data (w*h,0), m_width (w), m_height (h) { }
    Image& operator= (const Image&) = default;

    int width () const { return m_width; }
    int height () const { return m_height; }

    int& operator() (int i, int j) { return m_data[i+m_width*j]; }
    const int& operator() (int i, int j) const { return m_data[i+m_width*j]; }

  private:
    std::vector<int> m_data;
    int m_width = 0, m_height = 0;
};



inline std::ostream& operator<< (std::ostream& stream, const Image& im)
{
  stream << im.width() << " x " << im.height();
  return stream;
}

