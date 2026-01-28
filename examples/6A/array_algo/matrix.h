#pragma once

#include <array>
#include <ostream>
#include <format>
#include <stdexcept>

class Matrix3x3 {
  public:
    Matrix3x3 () = default;  // <- default constructor
    Matrix3x3 (const Matrix3x3&) = default;   // <- copy constructor
    // required for the transpose() template function:
    Matrix3x3 (int width, int height) {
      if (width != 3 || height != 3)
        throw std::runtime_error ("Matrix3x3 class can only be 3x3");
    }

    // construct by providing the data for the 3 rows of the matrix:
    Matrix3x3 (const std::array<float,3>& row1,
               const std::array<float,3>& row2,
               const std::array<float,3>& row3) :
      m_data ({ row1, row2, row3 }) { }

    int size (int axis) const { return 3; }   // <- size of matrix

    // get/set using function call operator:
    float& operator() (int i, int j) { return m_data[i][j]; }
    const float& operator() (int i, int j) const { return m_data[i][j]; }

    // define stream insertion operator to quickly display matrix contents:
    friend std::ostream& operator<< (std::ostream& stream, const Matrix3x3& M)
    {
      for (const auto& row: M.m_data) {
        for (auto v : row)
          stream << std::format ("{:5f} ", v);
        stream << "\n";
      }
      return stream;
    }

  private:
    // data are stored using a fixed-sized array of fixed-sized arrays:
    std::array<std::array<float,3>,3> m_data;
};

