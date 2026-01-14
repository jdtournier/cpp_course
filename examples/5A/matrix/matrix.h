#pragma once

#include <ostream>
#include <array>

// our matrix class to hold 3x3 matrices:
class Matrix {
  public:
    Matrix() = default;

    int rows() const { return 3; }
    int cols() const { return 3; }

    float& operator() (int i, int j) { return m_data[i][j]; }
    const float& operator() (int i, int j) const { return m_data[i][j]; }

  private:
    std::array<std::array<float,3>,3> m_data;
};

// stream insertion operator for Matrix class:
std::ostream& operator<< (std::ostream& stream, const Matrix& M);

// function to compute determinant of 3x3 matrix:
float compute_determinant (const Matrix& M);

