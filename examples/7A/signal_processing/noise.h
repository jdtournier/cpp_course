#pragma once

#include <random>

// A random noise generator, producing random samples from a Gaussian
// distribution of the stated standard deviation:
class RandomNoise {
  public:
    RandomNoise (double sd) :
      m_rng (std::random_device()()),
      m_dist (0.0, sd) { }

    double operator() () { return m_dist (m_rng); }

  private:
    std::mt19937 m_rng;
    std::normal_distribution<double> m_dist;
};


