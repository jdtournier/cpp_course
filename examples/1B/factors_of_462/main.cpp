#include <iostream>

int main()
{
  std::cout << "Factors of 462 are: ";

  for (int n = 2; n < 462; n++) {
    if (462%n == 0)
      std::cout << n << " ";
  }
  std::cout << "\n";

  return 0;
}
