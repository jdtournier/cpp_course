#include <iostream>

int factorial (int n)
{
  int out = 1;
  for (int m=2; m <= n; m++)
    out *= m;
  return out;
}

int main ()
{
  int n;
  std::cout << "Enter an integer: ";
  std::cin >> n;

  std::cout << "n! = " << factorial (n) << "\n";

  return 0;
}
