#include <iostream>
#include <stdexcept>

#include "debug.h"
#include "segment/tip.h"
#include "segment/straight.h"
#include "segment/bend.h"
#include "segment/rotate.h"
#include "segment/root.h"

int main (int argc, char* argv[])
{
  debug::set_verbose_mode (argc, argv);

  try { // Start of main processing:

    Segment::Tip tip (10.0);
    Segment::Bend bend (tip, 6.0);
    Segment::Straight straight (bend, 15.0);
    Segment::Rotate rotate (straight, 5.0);
    Segment::Root root (rotate);

    bend.set_angle (1.3);
    rotate.set_angle (std::numbers::pi/2.0);

    std::cout << "tip position: " << root.tip_position() << "\n";

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
