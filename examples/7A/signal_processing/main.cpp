#include <iostream>
#include <vector>

#include <termviz.h>

#include "noise.h"
#include "filter/gain.h"


int main ()
{
  std::vector<double> signal;
  RandomNoise noise (0.2);

  // generate a signal with noise:
  for (int n = 0; n < 100; n++)
    signal.push_back (std::sin (0.2*n) + noise());

  GainFilter gain (2.0);

  std::cout << gain.describe() << "\n";

  std::vector<double> filtered;
  for (auto s : signal)
    filtered.push_back (gain (s));

  termviz::figure()
    .plot (signal)
    .plot (filtered);

  return 0;
}

