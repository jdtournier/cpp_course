#include <iostream>

#include "image.h"

int main ()
{
  Image a;
  std::cout << "Image a: " << a << "\n";

  Image b (10,10);
  std::cout << "Image b: " << b << "\n";

  return 0;
}
