#include <iostream>
#include <fstream>
#include <stdexcept>
#include <format>
#include <vector>

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

  int val;
  std::vector<int> data;
  while (infile >> val)
    data.push_back (val);

  if (static_cast<int>(data.size()) != xdim * ydim)
    throw std::runtime_error (std::format (
          "amount of data in PGM file \"{}\" ({}) does not match dimensions ({}x{})",
          filename, data.size(), xdim, ydim));

  return 0;
}
