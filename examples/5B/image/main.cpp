#include <iostream>

#include "image.h"

int main ()
{
  Image a;
  std::cout << "Image a: " << a.width() << " x " << a.height() << "\n";

  Image b (10,10);
  std::cout << "Image b: " << b.width() << " x " << b.height() << "\n";

  return 0;
}
