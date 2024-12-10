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
    Segment::Bend bend3 (tip, 6.0);
    Segment::Straight straight3 (bend3, 15.0);
    Segment::Rotate rotate3 (straight3, 5.0);
    Segment::Bend bend2 (rotate3, 8.0);
    Segment::Straight straight2 (bend2, 20.0);
    Segment::Rotate rotate2 (straight2, 5.0);
    Segment::Bend bend1 (rotate2, 10.0);
    Segment::Straight straight1 (bend1, 30.0);
    Segment::Rotate rotate1 (straight1, 5.0);
    Segment::Root root (rotate1);

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
      std::cout << positions.back() << "\n";
    }

    std::vector<double> x, y, z;
    for (const auto& p : positions) {
      x.push_back (p[0]);
      y.push_back (p[1]);
      z.push_back (p[2]);
    }

    // plot projections of the tip trajectory
    // in the x,z plane (yellow)
    // in the y,z plane (pink)
    // in the x,y plane (blue)
    termviz::figure(600,600)
      .xlim(-40,80)
      .ylim(-40,120)
      .xticks (20)
      .yticks (20)
      .plot (x,z,2)
      .plot (y,z,3)
      .plot (x,y,4)
      .text ("(x,z)",80,120,1,1,2)
      .text ("(y,z)",80,115,1,1,3)
      .text ("(x,y)",80,110,1,1,4);

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
