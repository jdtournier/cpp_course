#include <iostream>
// to generate random numbers:
#include <random>

#include <termviz.h>

#include "running_average.h"

// demonstrate running average using random numbers, and plot original signal
// and its running average

int main ()
{
  // set up a random number generator:
  std::random_device rd;
  std::mt19937_64 gen(rd());
  // set up a Normal distribution sampler:
  std::normal_distribution<float> dist(10.0, 2.0);


  // set up the running average 'logger' object:
  RunningAverage<float> logger;

  std::vector<float> values, av_values;
  // generate random values and record them in the logger, while also recording
  // the values and the running average at that point:
  for (int n = 0; n < 100; n++) {
    float val = dist (gen);
    logger.record (val);
    values.push_back (val);
    av_values.push_back (logger.get_average());
  }

  // plot both original and running average values to the terminal:
  termviz::figure ().plot (values).plot (av_values);

  return 0;
}
