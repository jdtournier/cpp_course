#include <iostream>
#include <stdexcept>

#include "debug.h"
#include "segment/tip.h"

int main (int argc, char* argv[])
{
  debug::set_verbose_mode (argc, argv);

  try { // Start of main processing:

    Segment::Tip tip (20.0);
    Segment::Base root (tip, "root");

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
