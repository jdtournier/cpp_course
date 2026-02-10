#include <iostream>
#include <vector>
#include <array>

#include <termviz.h>


class LorenzAttractor {
  public:
    LorenzAttractor& set_initial_position (double x, double y, double z) {
      m_p = { x, y, z };
      return *this;
    }

    LorenzAttractor& set_parameters (double s, double r, double b) {
      m_sigma = s; m_rho = r; m_beta = b;
      return *this;
    }

    LorenzAttractor& set_time_step (double delta_t) {
      m_dt = delta_t;
      return *this;
    }

    std::array<std::vector<double>,3> simulate (int iterations)
    {
      double x = m_p[0], y = m_p[1], z = m_p[2];

      std::array<std::vector<double>,3> out;

      for (int i = 0; i < iterations; ++i) {
        // Lorenz Equations
        double dx = m_sigma * (y - x);
        double dy = x * (m_rho - z) - y;
        double dz = x * y - m_beta * z;

        // Euler integration
        x += m_dt * dx;
        y += m_dt * dy;
        z += m_dt * dz;

        out[0].push_back (x);
        out[1].push_back (y);
        out[2].push_back (z);
      }

      return out;
    }

  private:
    std::array<double,3> m_p = { 0.1, 0.0, 0.0 };
    double m_sigma = 10.0;
    double m_rho = 28.0;
    double m_beta = 8.0 / 3.0;
    double m_dt = 0.01;
};





int main()
{
  auto out = LorenzAttractor()
    .set_initial_position (1.0, 0.0, 20.0)
    .set_parameters (10.0, 28.0, 8.0/3.0)
    .set_time_step (0.005)
    .simulate (5000);


  termviz::figure (513,512)
    .plot (out[0], out[2])
    .grid (false, false)
    .xticks (false)
    .yticks (false);

  return 0;
}

