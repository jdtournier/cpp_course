#pragma once

#include <ostream>
#include <array>
#include <format>

// our matrix class to hold 3x3 matrices:
template <typename X> class Matrix {
  public:
    Matrix() = default;

    int rows() const { return 3; }
    int cols() const { return 3; }

    X& operator() (int i, int j) { return m_data[i][j]; }
    const X& operator() (int i, int j) const { return m_data[i][j]; }

  private:
    std::array<std::array<X,3>,3> m_data;
};

// stream insertion operator for Matrix class:
template <typename X> std::ostream& operator<< (std::ostream& stream, const Matrix<X>& M)
{
  // Note this displays the matrix content over 3 lines.
  // There are other ways to display this if you wish!
  stream << std::format (
      "3x3 matrix with contents:\n"
      "    {:6.4f} {:6.4f} {:6.4f}\n"
      "    {:6.4f} {:6.4f} {:6.4f}\n"
      "    {:6.4f} {:6.4f} {:6.4f}\n",
      M(0,0), M(0,1), M(0,2),
      M(1,0), M(1,1), M(1,2),
      M(2,0), M(2,1), M(2,2));

  return stream;
}


// function to compute determinant of 3x3 matrix:
template <typename X> X compute_determinant (const Matrix<X>& M)
{
  return M(0,0) * ( M(1,1)*M(2,2) - M(2,1)*M(1,2) )
       - M(1,0) * ( M(0,1)*M(2,2) - M(2,1)*M(0,2) )
       + M(2,0) * ( M(0,1)*M(1,2) - M(1,1)*M(0,2) );
}
