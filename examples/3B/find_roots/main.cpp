#include <iostream>
#include <string>

float eval_function (float x)     { return x*x*x - 3.0*x + 3.0; }
float eval_derivative (float x)   { return 3.0*x*x - 3.0; }

int main()
{
  float dx, x = 0.0;
  if (argc >= 2) 
    x = std::stod (argv[1]);

  do {
    float dfx = eval_derivative (x);
    if (dfx == 0.0)
      throw std::runtime_error ("derivative at x = " + std::to_string(x) + " is zero. "
                                "Maybe try a different initial guess?");
    dx = -eval_function (x) / dfx;
    x += dx;
  } while (dx != 0.0);

  std::cout << "solution is at x = " << x << "\n";

  return 0;
}
