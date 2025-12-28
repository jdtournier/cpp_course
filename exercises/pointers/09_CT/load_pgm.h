#ifndef __PGM_H__
#define __PGM_H__

#include <fstream>
#include <string>
#include <sstream>
#include <exception>
#include <limits>

#include "terminal_graphics.h"


// Simple function to load an ascii-encoded PGM grayscale image.
// This returns an object of type TG::Image<ValueType>


template <typename ValueType = unsigned char>
TG::Image<ValueType> load_pgm (const std::string& pgm_filename)
{
  std::ifstream in (pgm_filename);
  if (!in)
    throw std::runtime_error ("failed to open input PGM file \"" + pgm_filename + "\"");

  // strip out all comments, and present stringstream of clean file contents:
  std::string line;
  std::stringstream in_clean;
  while (std::getline (in, line)) {
    in_clean << line.substr (0, line.find_first_of('#')) << "\n";
  }

  std::string magic;
  in_clean >> magic;
  if (magic != "P2")
    throw std::runtime_error ("input file \"" + pgm_filename + "\" is not in expected PGM format");

  int xdim, ydim, maxval;
  in_clean >> xdim >> ydim >> maxval;

  if (maxval >= 65536)
    throw std::runtime_error ("PGM file \"" + pgm_filename + "\" is badly formed: maxval exceeds 65536");
  if (maxval <= 0)
    throw std::runtime_error ("PGM file \"" + pgm_filename + "\" is badly formed: maxval lower than or equal to zero");

  if (maxval > std::numeric_limits<ValueType>::max())
    throw std::runtime_error ("maximum intensity in PGM file \"" + pgm_filename + "\" exceeds range of data type used");

  TG::Image<ValueType> im (xdim, ydim);

  for (int y = 0; y < im.height(); ++y) {
    for (int x = 0; x < im.width(); ++x) {
      int val;
      in_clean >> val;
      im(x,y) = static_cast<ValueType> (val);
    }
  }

  return im;
}

#endif
