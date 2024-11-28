#pragma once

#include <array>
#include <vector>
#include <stdexcept>

class Image {
  public:
    Image (int xdim, int ydim) :
      m_dim { xdim, ydim }, m_data (xdim*ydim, 0) { }

    Image (int xdim, int ydim, const std::vector<int>& data) :
      m_dim {xdim, ydim }, m_data (data) {
        if (static_cast<int> (m_data.size()) != m_dim[0] * m_dim[1])
          throw std::runtime_error ("dimensions mismatch between image sizes and data vector");
      }

    int width () const { return m_dim[0]; }
    int height () const { return m_dim[1]; }


    const std::vector<int>& data () const { return m_data; }

    int get (int x, int y) const { return m_data[x + m_dim[0]*y]; }
    void set (int x, int y, int value)  { m_data[x + m_dim[0]*y] = value; }

  private:
    std::array<int,2> m_dim;
    std::vector<int> m_data;
};

