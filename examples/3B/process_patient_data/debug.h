#pragma once

// We define a global variable to specify whether verbose mode is enabled.
// By default, this should be false.
inline bool verbose_mode = false;

// check for presence of option_name in command-line arguments.
// If found, remove the option from the argument list, and set the verbose_mode global variable to true.
void set_verbose_mode (int& argc, char* argv[]);
