#include <iostream>
#include <stdexcept>
#include <termviz.h>

#include "debug.h"
#include "load_data.h"
#include "stats.h"


int main (int argc, char* argv[])
{
  try {
    // main processing block:

    debug::set_verbose_mode (argc, argv);

    if (argc < 2)
      throw std::out_of_range ("expected at least one argument for filename of input file");

    auto list = load_patient_data (argv[1]);

    for (const auto& pat : list)
      std::cout << pat.ID << ": " << compute_mean (pat.data) << " ± " << compute_stddev (pat.data) << "\n";

    auto fig = termviz::figure();
    for (const auto& p : list)
        fig.plot (p.data);

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
