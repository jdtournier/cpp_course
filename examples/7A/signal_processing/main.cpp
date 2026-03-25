#include <iostream>
#include <vector>

#include <termviz.h>

#include "noise.h"


int main ()
{
  std::vector<double> signal;
  RandomNoise noise (0.2);

  // generate a signal with noise:
  for (int n = 0; n < 100; n++)
    signal.push_back (std::sin (0.2*n) + noise());

  termviz::figure()
    .plot (signal);

  return 0;
}

