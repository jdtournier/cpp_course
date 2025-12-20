#include <iostream>

int main()
{
  std::cout << "Primes to 100 are: ";

  for (int n = 2; n < 100; n++) {
    bool is_prime = true;
    for (int m = 2; m < n; m++) {
      if (n%m == 0)
        is_prime = false;
    }
    if (is_prime)
      std::cout << n << " ";
  }
  std::cout << "\n";

  return 0;
}
