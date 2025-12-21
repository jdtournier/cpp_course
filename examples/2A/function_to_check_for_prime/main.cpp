#include <iostream>

bool is_prime (int in)
{
  for (int n = 2; n < in/2; n++)
    if (in%n == 0)
      return false;
  return true;
}

int main ()
{
  int num_found = 0;
  int n = 2;

  while (num_found <= 50) {
    if (is_prime(n)) {
      num_found++;
      std::cout << n << " ";
    }
    n++;
  }
  std::cout << "\n";

  return 0;
}
