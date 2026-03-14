#pragma once

#include <ostream>
#include <array>
#include <format>

// our matrix class to hold MxN matrices:
template <typename X, int M, int N> class Matrix {
  public:
    Matrix() = default;

    int rows() const { return M; }
    int cols() const { return N; }

    X& operator() (int i, int j) { return m_data[i][j]; }
    const X& operator() (int i, int j) const { return m_data[i][j]; }

  private:
    std::array<std::array<X,N>,M> m_data;
};

// stream insertion operator for Matrix class:
template <typename X, int M, int N> std::ostream& operator<< (std::ostream& stream, const Matrix<X,M,N>& mat)
{
  // Note this displays the matrix content over 3 lines.
  // There are other ways to display this if you wish!
  stream << std::format ("{}x{} matrix with contents:\n", mat.rows(), mat.cols());
  for (int i = 0; i < mat.rows(); i++) {
    for (int j = 0; j < mat.cols(); j++)
      stream << std::format (" {:6.4f}", mat(i,j));
    stream << "\n";
  }
  return stream;
}

