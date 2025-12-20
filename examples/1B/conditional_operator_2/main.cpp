#include <iostream>

int main()
{
  float x;
  std::cout << "Please enter the floating-point value to be tested: ";
  std::cin >> x;
  if (x < 0.0)
    std::cout << "ERROR: the value entered (" << x << ") is less than zero\n";
  else if (x > 50.0)
    std::cout << "The value entered (" << x << ") exceeds 50\n";
  else
    std::cout << "The value entered (" << x << ") does not exceed 50\n";

  return 0;
}
