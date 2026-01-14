#include <iostream>

#include "matrix.h"

int main()
{
  Matrix M;
  M(0,0) = 1.0; M(0,1) = 0.3; M(0,2) = 0.4;
  M(1,0) = 0.3; M(1,1) = 1.0; M(1,2) = 0.5;
  M(2,0) = 0.4; M(2,1) = 0.5; M(2,2) = 1.0;

  std::cout << "Matrix is " << M << "\n";
  std::cout << "Determinant = " << compute_determinant (M) << "\n";

  return 0;
}

