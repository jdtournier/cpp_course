#include <iostream>
#include <format>


double fraction_in_circle (int grid_size)
{
  // use long long int as the count can get very large:
  long long int n_in_circle = 0;

  // the increment between samples:
  const double step = 1.0/grid_size;

  for (double y = 0.0; y < 1.0; y += step)
    for (double x = 0.0; x < 1.0; x += step)
      if (x*x + y*y < 1.0)
        n_in_circle++;

  // convert to double to ensure subsequent calculation works as expected:
  const double size = grid_size;

  return n_in_circle / (size*size);
}




int main (int argc, char* argv[0])
{
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " grid_size\n";
    return 1;
  }

  const int grid_size = std::stoi(argv[1]);
  const double fraction = fraction_in_circle (grid_size);

  std::cout << std::format ("fraction in circle: {}%\n", 100.0*fraction);
  std::cout << std::format ("estimate of pi = {:.15f}\n", 4.0*fraction);

  return 0;
}

