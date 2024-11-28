#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm>
#include <format>

#include "debug.h"
#include "pgm.h"
#include "dataset.h"

int main (int argc, char* argv[])
{
  debug::set_verbose_mode (argc, argv);

  if (argc < 2) {
    std::cerr << "ERROR: missing arguments - expected 1 arguments: image\n";
    return 1;
  }

  try { // Start of main processing:

    // We use aggregate initialisation to construct the
    // std::vector<std::string> argument expected by the Dataset constructor,
    // relying one of the std::vector constructors:
    Dataset data ({ argv+1, argv+argc });

    int x = data.get(0).width()/2;
    int y = data.get(0).height()/2;

    std::cerr << std::format ("image values at pixel ({},{}) = [ ", x, y);
    for (const auto& val : data.get_timecourse (x,y))
      std::cerr << val << " ";
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
