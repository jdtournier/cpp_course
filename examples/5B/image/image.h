#pragma once

#include <vector>
#include <ostream>
#include <stdexcept>

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

    void resize (int w, int h) {
      m_data.resize (w*h);
      m_width = w;
      m_height = h;
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


// helper function: throw an exception is sizes of a & b don't match:
inline void check_sizes_match (const Image& a, const Image& b) {
  if (a.width() != b.width() || a.height() != b.height())
    throw std::runtime_error ("size of images do not match");
}


// relational operators:
inline bool operator< (const Image& a, const Image& b)
{
  check_sizes_match (a, b);
  for (int j = 0; j < a.height(); j++)
    for (int i = 0; i < a.width(); i++)
      if (!( a(i,j) < b(i,j) ))
        return false;
  return true;
}

inline bool operator<= (const Image& a, const Image& b)
{
  check_sizes_match (a, b);
  for (int j = 0; j < a.height(); j++)
    for (int i = 0; i < a.width(); i++)
      if (!( a(i,j) <= b(i,j) ))
        return false;
  return true;
}

inline bool operator> (const Image& a, const Image& b)
{
  check_sizes_match (a, b);
  for (int j = 0; j < a.height(); j++)
    for (int i = 0; i < a.width(); i++)
      if (!( a(i,j) > b(i,j) ))
        return false;
  return true;
}

inline bool operator>= (const Image& a, const Image& b)
{
  check_sizes_match (a, b);
  for (int j = 0; j < a.height(); j++)
    for (int i = 0; i < a.width(); i++)
      if (!( a(i,j) >= b(i,j) ))
        return false;
  return true;
}




// relational operators: Image <=> int
inline bool operator< (const Image& a, int b)
{
  for (int j = 0; j < a.height(); j++)
    for (int i = 0; i < a.width(); i++)
      if (!( a(i,j) < b ))
        return false;
  return true;
}

inline bool operator<= (const Image& a, int b)
{
  for (int j = 0; j < a.height(); j++)
    for (int i = 0; i < a.width(); i++)
      if (!( a(i,j) <= b ))
        return false;
  return true;
}

inline bool operator> (const Image& a, int b)
{
  for (int j = 0; j < a.height(); j++)
    for (int i = 0; i < a.width(); i++)
      if (!( a(i,j) > b ))
        return false;
  return true;
}

inline bool operator>= (const Image& a, int b)
{
  for (int j = 0; j < a.height(); j++)
    for (int i = 0; i < a.width(); i++)
      if (!( a(i,j) >= b ))
        return false;
  return true;
}

// relational operators: int <=> Image
inline bool operator< (int a, const Image& b) { return b>a; }
inline bool operator<= (int a, const Image& b) { return b>=a; }
inline bool operator> (int a, const Image& b) { return b<a; }
inline bool operator>= (int a, const Image& b) { return b<=a; }


// arithmetic operators: Image <=> Image
inline Image operator+ (const Image& a, const Image& b)
{
  check_sizes_match (a, b);
  Image c (a.width(), a.height());
  for (int j = 0; j < a.height(); j++)
    for (int i = 0; i < a.width(); i++)
      c(i,j) = a(i,j) + b(i,j);
  return c;
}

inline Image operator- (const Image& a, const Image& b)
{
  check_sizes_match (a, b);
  Image c (a.width(), a.height());
  for (int j = 0; j < a.height(); j++)
    for (int i = 0; i < a.width(); i++)
      c(i,j) = a(i,j) - b(i,j);
  return c;
}

inline Image operator* (const Image& a, const Image& b)
{
  check_sizes_match (a, b);
  Image c (a.width(), a.height());
  for (int j = 0; j < a.height(); j++)
    for (int i = 0; i < a.width(); i++)
      c(i,j) = a(i,j) * b(i,j);
  return c;
}

inline Image operator/ (const Image& a, const Image& b)
{
  check_sizes_match (a, b);
  Image c (a.width(), a.height());
  for (int j = 0; j < a.height(); j++)
    for (int i = 0; i < a.width(); i++)
      c(i,j) = a(i,j) / b(i,j);
  return c;
}

