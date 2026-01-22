#include <iostream>

template <typename T> T get_max (T a, T b)
{
  if (a>b)
    return a;
  else
    return b;
}


int main ()
{
  int x = 324, y = 129;
  std::cout << "max of " << x << " and " << y << " is " << get_max(x,y) << "\n";

  double f = 0.32492, g = 0.92374;
  std::cout << "max of " << f << " and " << g << " is " << get_max(f,g) << "\n";

  // This will not compile!
  // std::cout << "max of " << x << " and " << g << " is " << get_max(x,g) << "\n";

  return 0;
}

