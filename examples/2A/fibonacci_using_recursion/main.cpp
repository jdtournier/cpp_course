#include <iostream>

int fibonacci (int n)
{
  if (n > 1)
    return fibonacci(n-1) + fibonacci(n-2);
  else
    return n;
}

// Alernatively, using the ternary operator:
// int fibonacci (int n) { return n>1 ? fibonacci(n-1)+fibonacci(n-2) : n; }

int main ()
{
  int nmax;
  std::cout << "Enter the number of elements to display: ";
  std::cin >> nmax;

  for (int n = 0; n < nmax; n++)
    std::cout << fibonacci (n) << " ";
  std::cout << "\n";

  return 0;
}
