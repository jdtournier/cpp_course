#include <string>
#include "debug.h"

namespace debug {

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

}
