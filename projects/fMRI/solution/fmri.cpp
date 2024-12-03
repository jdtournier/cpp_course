#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <format>

#include <termviz.h>

#include "debug.h"
#include "pgm.h"
#include "dataset.h"
#include "task.h"
#include "utils.h"


struct Pixel {
  int x = -1;
  int y = -1;
};

Pixel get_pixel_cmdline (int& argc, char* argv[])
{
  for (int n = 1; n < argc; n++) {
    if (argv[n] == std::string("-p")) {
      if (argc-n < 3)
        throw std::runtime_error ("not enough arguments to '-p' option (expected '-p x y')");
      argc -= 3;
      Pixel p { std::stoi (argv[n+1]), std::stoi (argv[n+2]) };
      debug::log (std::format ("pixel position set manually to ({}, {}) via command-line", p.x, p.y));
      // shuffle all remaining arguments back 3 places, effectively removing
      // the option and its arguments from the argument list:
      for (int m = n; m < argc; m++)
        argv[m] = argv[m+3];

      return p;
    }
  }

  // if not found, return invalid location:
  return { -1, -1 };
}





int main (int argc, char* argv[])
{
  debug::set_verbose_mode (argc, argv);

  if (argc < 3) {
    std::cerr << "ERROR: missing arguments - expected least 2 arguments: taskfile followed by list of images\n";
    return 1;
  }

  try { // Start of main processing:

    // need to call this before constructing data set, to remove the -p option
    // from the list of arguments (if present) before constructing the Dataset:
    auto pixel = get_pixel_cmdline (argc, argv);

    auto task = load_task (argv[1]);

    // We use aggregate initialisation to construct the
    // std::vector<std::string> argument expected by the Dataset constructor,
    // relying one of the std::vector constructors:
    Dataset data ({ argv+2, argv+argc });

    if (task.size() != data.size())
      throw std::runtime_error ("number of time points in task file does not match dataset");

    termviz::imshow (termviz::magnify (data[0], 4), 0, 4000);

    // default values if x & y not set (<0):
    if (pixel.x < 0 || pixel.y < 0) {
      auto im_corr = correlation_coefficient (task, data);
      termviz::imshow (termviz::magnify (im_corr, 4), -1000, 1000, termviz::jet());

      return 0;
    }

    // otherwise, extract that pixel's timecourse and plot against task:
    if (pixel.x >= data[0].width() || pixel.y >= data[0].height())
      throw std::runtime_error ("pixel position is out of bounds");

    auto signal = data.get_timecourse (pixel.x, pixel.y);
    auto minval = *std::min_element (signal.begin(), signal.end());
    auto maxval = *std::max_element (signal.begin(), signal.end());
    termviz::figure()
      .plot (signal)
      .plot (rescale (task, minval, maxval), 3);

    std::cerr << std::format ("correlation_coefficient at ({},{}) = {}\n",
        pixel.x, pixel.y, correlation_coefficient (signal, task));

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
