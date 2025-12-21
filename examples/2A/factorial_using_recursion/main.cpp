#include <iostream>

int factorial (int n)
{
  if (n > 1)
    return n*factorial(n-1);
  else
    return n;
}

// alternatively, using the ternary operator:
// int factorial (int n) { return n>1 ? n*factorial(n-1) : n; }

int main ()
{
  int n;
  std::cout << "Enter an integer: ";
  std::cin >> n;

  std::cout << "n! = " << factorial (n) << "\n";

  return 0;
}
