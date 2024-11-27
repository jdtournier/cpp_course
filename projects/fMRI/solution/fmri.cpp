#include <iostream>
#include <stdexcept>

#include "debug.h"

int main (int argc, char* argv[])
{
  debug::set_verbose_mode (argc, argv);

  if (argc < 2) {
    std::cerr << "ERROR: missing arguments - expected 1 arguments: image\n";
    return 1;
  }

  try { // Start of main processing:


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
