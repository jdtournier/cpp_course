#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm>
#include <format>

#include "debug.h"
#include "pgm.h"

int main (int argc, char* argv[])
{
  debug::set_verbose_mode (argc, argv);

  if (argc < 2) {
    std::cerr << "ERROR: missing arguments - expected 1 arguments: image\n";
    return 1;
  }

  try { // Start of main processing:

    auto slice = load_pgm (argv[1]);

    std::cerr << std::format ("image \"{}\" loaded, size {}x{}\n", argv[1], slice.width(), slice.height());

    int x = slice.width()/2;
    int y = slice.height()/2;
    std::cerr << std::format ("image value at pixel ({},{}) = {}\n", x, y, slice.get (x,y));

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
