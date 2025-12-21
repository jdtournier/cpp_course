#include <iostream>

double pow2 (double in)
{
  return in*in;
}

int main ()
{
  double in = 12.34;
  std::cout << "pow2(" << in << ") = " << pow2(in) << "\n";

  return 0;
}
