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

    std::vector<Image> slices;
    for (unsigned int n = 1; n < argc; ++n)
      slices.push_back (load_pgm (argv[n]));

    // check that dimensions all match up:
    for (unsigned int n = 1; n < slices.size(); ++n) {
      if ( (slices[n].width() != slices[n-1].width()) ||
          (slices[n].height() != slices[n-1].height()) )
        throw std::runtime_error ("dimensions do not match across slices");
    }

    std::cerr << std::format (
        "loaded {} slices of size {}x{}\n",
        slices.size(), slices[0].width(), slices[0].height());

    int x = slices[0].width()/2;
    int y = slices[0].height()/2;

    std::cerr << std::format ("image values at pixel ({},{}) = [ ", x, y);
    for (const auto& slice : slices)
      std::cerr << slice.get (x,y) << " ";
    std::cerr << "]\n";

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
