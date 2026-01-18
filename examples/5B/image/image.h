#pragma once

#include <vector>
#include <ostream>

class Image {
  public:
    Image() = default;
    Image(const Image&) = default;
    Image (int w, int h) : m_data (w*h,0), m_width (w), m_height (h) { }
    Image& operator= (const Image&) = default;

    bool operator== (const Image& other) const {
      if (m_width != other.m_width || m_height != other.m_height)
        return false;
      for (int j = 0; j < height(); j++)
        for (int i = 0; i < width(); i++)
          if ((*this)(i,j) != other(i,j))
            return false;
      return true;
    }

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

