#include <iostream>
#include <stdexcept>
#include <format>
#include <termviz.h>

#include "debug.h"
#include "load_data.h"
#include "patient.h"


int main (int argc, char* argv[])
{
  try {
    // main processing block:

    debug::set_verbose_mode (argc, argv);

    if (argc < 2)
      throw std::out_of_range ("expected at least one argument for filename of input file");

    auto list = load_patient_data (argv[1]);
    if (!list)
      throw std::runtime_error (std::format ("input file \"{}\" contains no data!", argv[1]));

    for (int n = 0; n < list.size(); n++)
      std::cout << list[n].ID() << ": " << list[n].get_mean() << " ± " << list[n].get_stddev() << "\n";

    auto fig = termviz::figure();
    for (int n = 0; n < list.size(); n++)
      fig.plot (list[n].data());

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
