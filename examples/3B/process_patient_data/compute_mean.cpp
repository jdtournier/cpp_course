#include <iostream>
#include <stdexcept>

#include "load_data.h"
#include "stats.h"

// We define a global variable to specify whether verbose mode is enabled.
// By default, this should be false.
bool verbose_mode = false;

// check for presence of option_name in command-line arguments.
// If found, remove the option from the argument list, and set the verbose_mode global variable to true.
void set_verbose_mode (int& argc, char* argv[])
{
  for (int n = 1; n < argc; n++) {
    if (argv[n] == std::string("-v")) {
      argc--;
      // shuffle remaining arguments back one place:
      for (int m = n; m < argc; m++)
        argv[m] = argv[m+1];
      verbose_mode = true;
      break;
    }
  }
}



int main (int argc, char* argv[])
{
  try {
    // main processing block:

    set_verbose_mode (argc, argv);

    if (verbose_mode)
      std::cerr << "running in verbose mode\n";

    if (argc < 2)
      throw std::out_of_range ("expected at least one argument for filename of input file");

    auto data = load_patient_data (argv[1]);

    for (const auto& pat : data)
      std::cout << compute_mean (pat) << " ± " << compute_stddev (pat) << "\n";

    // end of main processing block
  }
  catch (std::out_of_range& err) {
    // not enough arguments provided: print out command usage instead:
    std::cerr << "Invalid number of arguments. Command usage:\n\n    " << argv[0] << " input_file\n\n";
    return 1;
  }
  catch (std::exception& err) {
    // if any exceptions were thrown, we can handle them here:
    std::cerr << "ERROR: " << err.what() << " - aborting\n";
    return 1;
  }
  catch (...) { // <- the catch-all handler
    std::cerr << "ERROR: exception of unknown type was thrown - aborting\n";
    return 1;
  }

  return 0;
}
