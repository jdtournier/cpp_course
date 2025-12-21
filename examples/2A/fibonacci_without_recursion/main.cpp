#include <iostream>

int fibonacci (int n)
{
  if (n < 1)
    return n;

  int fn;
  int f1 = 1;
  int f2 = 0;

  // we keep a record of the last two numbers in the sequence
  // along with the current result:
  for (int i = 1; i < n; i++) {
    fn = f1+f2;
    f2 = f1;
    f1 = fn;
  }

  return fn;
}

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
