#include <iostream>
#include <exception>

#include "array.h"


int main (int argc, char* argv[])
{
  if (argc != 4) {
    std::cerr <<
      "ERROR: unexpected number of arguments\n"
      "\n"
      "  usage: add_arrays input1 input2 output\n"
      "\n"
      "  - input1 & input2 are the two text files containing the arrays\n"
      "    of values to add.\n"
      "\n"
      "  - output is the nome of the text file that will be produced to\n"
      "    store the sum of the two arrays.\n\n";

    return 1;
  }

  try {
    // main processing block:

    auto v1 = load_array (argv[1]);
    auto v2 = load_array (argv[2]);

    save_array (argv[3], add_arrays (v1,v2));

    // end of main processing block
  }
  catch (std::exception& err) {
    std::cerr << "ERROR: " << err.what() << " - aborting\n";
    return 1;
  }
  catch (...) {
    std::cerr << "ERROR: exception of unknown type was thrown - aborting\n";
    return 1;
  }

  return 0;
}
