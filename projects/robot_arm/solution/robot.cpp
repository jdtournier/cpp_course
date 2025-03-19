#include <iostream>
#include <stdexcept>

#include <termviz.h>

#include "debug.h"
#include "load_parameters.h"
#include "segment/tip.h"
#include "segment/straight.h"
#include "segment/bend.h"
#include "segment/rotate.h"
#include "segment/root.h"



constexpr double speed_threshold = 20.0;
constexpr double accel_threshold = 20.0;


struct TrajectoryInfo {
  Point final_position;
  double max_speed, max_accel;
};



TrajectoryInfo plot_trajectory (const std::vector<Point>& positions, const double time_interval)
{
  std::vector<double> x, y, z, speed, accel;

  for (int n = 0; n < static_cast<int> (positions.size()); ++n) {
    const Point& p (positions[n]);
    const Point& p_prev (n > 0 ? positions[n-1] : p);
    const Point& p_next (n < static_cast<int>(positions.size())-1 ? positions[n+1] : p);

    speed.push_back (length (p_next-p_prev)/(2.0*time_interval));
    accel.push_back (length ((p_next-p) - (p-p_prev)) / (time_interval*time_interval));

    debug::log (
        std::format ("tip position: [ {:6.3f} {:6.3f} {:6.3f} ], speed: {:6.3f}, acceleration: {:.3f}",
          p[0], p[1], p[2], speed.back(), accel.back()));

    x.push_back (p[0]);
    y.push_back (p[1]);
    z.push_back (p[2]);
  }

  auto xmin = std::min (std::ranges::min (x), std::ranges::min (y)) - 10;
  auto xmax = std::max (std::ranges::max (x), std::ranges::max (y)) + 10;

  auto ymin = std::min (std::ranges::min (y), std::ranges::min (z)) - 10;
  auto ymax = std::max (std::ranges::max (y), std::ranges::max (z)) + 10;

  std::cout << "3D view:\n";
  termviz::figure(600,600)
    .xlim(xmin,xmax)
    .ylim(ymin,ymax)
    .xticks (20)
    .yticks (20)
    .plot (x,z,2)
    .plot (y,z,3)
    .plot (x,y,4)
    .text ("(x,z)", xmax, ymax, 1, 1, 2)
    .text ("(y,z)", xmax, ymax, 1, 2, 3)
    .text ("(x,y)", xmax, ymax, 1, 3, 4);

  ymax = std::max (std::ranges::max (speed), std::ranges::max (accel)) + 10;

  std::cout << "Tip speed (cm/s) and acceleration (cm/s²):\n";
  termviz::figure()
    .ylim (0, ymax)
    .plot (speed, 2)
    .plot (accel, 3)
    .text ("speed", speed.size()-1, ymax, 1, 1, 2)
    .text ("acceleration", speed.size()-1, ymax, 1, 2, 3);

  return { positions.back(), std::ranges::max (speed), std::ranges::max (accel) };
}




int main (int argc, char* argv[])
{
  debug::set_verbose_mode (argc, argv);

  if (argc < 2) {
    std::cerr << "expected parameter file as first argument\n";
    return 1;
  }

  try { // Start of main processing:

    // set up robot arm:

    Segment::Tip tip (10.0);
    Segment::Bend bend3 (&tip, 6.0);
    Segment::Straight straight3 (&bend3, 15.0);
    Segment::Rotate rotate3 (&straight3, 5.0);
    Segment::Bend bend2 (&rotate3, 8.0);
    Segment::Straight straight2 (&bend2, 20.0);
    Segment::Rotate rotate2 (&straight2, 5.0);
    Segment::Bend bend1 (&rotate2, 10.0);
    Segment::Straight straight1 (&bend1, 30.0);
    Segment::Rotate rotate1 (&straight1, 5.0);
    Segment::Root root (&rotate1);

    // read parameter list:
    auto params = load_parameters (argv[1]);

    std::vector<Point> positions;

    for (const auto& p : params) {

      rotate1.set_angle (p[0]);
      bend1.set_angle (p[1]);
      rotate2.set_angle (p[2]);
      bend2.set_angle (p[3]);
      rotate3.set_angle (p[4]);
      bend3.set_angle (p[5]);

      positions.push_back (root.tip_position());
    }

    auto [ tip_pos, max_speed, max_accel ] = plot_trajectory (positions, 0.1);

    std::cout << "Final tip position: " << tip_pos << "\n";
    std::cout << "Maximum speed: " << max_speed << " cm/s\n";
    std::cout << "Maximum acceleration: " << max_accel << " cm/s²\n";

    if (max_speed < speed_threshold && max_accel < accel_threshold) {
      std::cout << "Both speed and acceleration remain within safe limits\n";
      return 0;
    }


    // speed and/or acceleration exceed threshold - report and raise an error:

    std::string report = "tip ";
    if (max_speed >= speed_threshold)
      report += "speed";

    if (max_accel >= accel_threshold) {
      if (max_speed >= speed_threshold)
        report += " and ";
      report += "acceleration";
    }

    throw std::runtime_error (report + " above safety limits");

  } // end of main processing

  // error handling from here:
  catch (std::exception& excp) {
    std::cerr << "ERROR: " << excp.what() << " - aborting\n";
    return 1;
  }
  catch (...) {
    std::cerr << "ERROR: unknown exception thrown - aborting\n";
    return 1;
  }

  return 0;
}
