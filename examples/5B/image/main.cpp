#include <iostream>

#include "image.h"

int main ()
{
  Image a;
  std::cout << "Image a: " << a << "\n";

  Image b (10,10);
  std::cout << "Image b: " << b << "\n";

  std::cout << "a == b: " << (a==b) << "\n";
  std::cout << "a != b: " << (a!=b) << "\n";

  auto c = b;

  std::cout << "b == c: " << (b==c) << "\n";
  std::cout << "b != c: " << (b!=c) << "\n";

  c(1,1) = 1;

  std::cout << "b == c: " << (b==c) << "\n";
  std::cout << "b != c: " << (b!=c) << "\n";

  return 0;
}
