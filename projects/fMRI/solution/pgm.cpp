#include <iostream>
#include <fstream>
#include <stdexcept>
#include <format>

#include "debug.h"
#include "pgm.h"

int load_pgm (const std::string& filename)
{
  debug::log ("loading PGM file \"" + filename + "\"...");

  std::ifstream infile (filename);
  if (!infile)
    throw std::runtime_error ("unable to open file \"" + filename + "\"");

  std::string magic_number;
  infile >> magic_number;
  if (magic_number != "P2")
    throw std::runtime_error ("file \"" + filename + "\" is not in plain PGM format");

  int xdim, ydim, maxval;
  infile >> xdim >> ydim >> maxval;

  debug::log (std::format (
        "PGM file \"{}\" contains {}x{} image with maximum value {}",
        filename, xdim, ydim, maxval));

  return 0;
}
