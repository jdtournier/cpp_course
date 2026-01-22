#include <iostream>
#include <format>

template <typename T> inline T pow3 (T x) { return x*x*x; }

int main()
{
  int i = 21;
  float f = 23.12;
  double d = 92.34;

  std::cout << std::format ("using {}: pow3({}) = {}\n", "int", i, pow3(i));
  std::cout << std::format ("using {}: pow3({}) = {}\n", "float", f, pow3(f));
  std::cout << std::format ("using {}: pow3({}) = {}\n", "double", d, pow3(d));

  return 0;
}

