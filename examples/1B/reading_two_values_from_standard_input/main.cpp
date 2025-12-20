#include <iostream>

int main()
{
  float x, y;
  std::cout << "Please enter the two floating-point values to be multiplied: ";
  std::cin >> x >> y;
  std::cout << "The product of " << x << " x " << y << " is " << x*y << "\n";

  return 0;
}
