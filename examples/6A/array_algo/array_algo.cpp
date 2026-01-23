#include <iostream>

#include "matrix.h"

int main ()
{
  Matrix3x3 M ({ 0.1, 0.2, 0.3 },
               { 0.4, 0.5, 0.6 },
               { 0.7, 0.8, 0.9 });

  std::cout << "M = \n" << M << "\n";

  return 0;
}
