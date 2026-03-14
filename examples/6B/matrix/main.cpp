#include <iostream>

#include "matrix.h"

int main()
{
  Matrix<double,3,4> M;
  M(0,0) = 1.0; M(0,1) = 0.3; M(0,2) = 0.4; M(0,3) = -1.5;
  M(1,0) = 0.3; M(1,1) = 1.0; M(1,2) = 0.5; M(1,3) = 2.1;
  M(2,0) = 0.4; M(2,1) = 0.5; M(2,2) = 1.0; M(2,3) = -0.1;

  std::cout << "Matrix is " << M << "\n";

  return 0;
}

