#include <iostream>
#include <cmath>

inline int factorial (int n)
{
  int f = 1;
  for (int i = 2; i <= n; i++)
    f *= i;
  return f;
}



template <int N, typename X> double sin (X x)
{
  X val = 0.0;
  for (int n = 0; n < N; n++)
    val += std::pow (-1.0, n) * std::pow (x, 2*n+1) / factorial(2*n+1);
  return val;
}

template <int N, typename X> double cos (X x)
{
  X val = 0.0;
  for (int n = 0; n < N; n++)
    val += std::pow (-1.0, n) * std::pow (x, 2*n) / factorial(2*n);
  return val;
}



int main (int argc, char* argv[])
{
  if (argc < 2) {
    std::cerr << "ERROR: provide value of x as first argument\n";
    return 1;
  }

  double x = std::stod (argv[1]);

  std::cout << "sin(x) ≈ " << sin<10> (x)
    << " (actual answer: " << std::sin (x) << ")\n";

  std::cout << "cos(x) ≈ " << cos<10> (x)
    << " (actual answer: " << std::cos (x) << ")\n";

  return 0;
}
