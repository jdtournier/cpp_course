#include <iostream>
#include <string>
#include <stdexcept>

#include "fragments.h"
#include "overlap.h"
#include "debug.h"
#include "shotgun_sequencer.h"

int main (int argc, char* argv[])
{
  debug::set_verbose_mode (argc, argv);

  if (argc < 3) {
    std::cerr << "ERROR: missing arguments - expected 2 arguments: input_fragments output_sequence\n";
    return 1;
  }

  try { // Start of main processing:

    auto fragments = load_fragments (argv[1]);

    ShotgunSequencer solver (10);
    solver.init (fragments);

    std::cerr << "initial sequence has size " << solver.sequence().size() << "\n";

    while (solver.iterate());

    solver.check_remaining_fragments();

    std::cerr << "final sequence has length " << solver.sequence().size() << "\n";

    write_sequence (argv[2], solver.sequence());

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
