#include <vector>
#include <string>
#include <format>
#include <stdexcept>

#include "debug.h"
#include "pgm.h"
#include "dataset.h"

void Dataset::load (const std::vector<std::string>& filenames)
{
  m_slices.clear();

  if (filenames.empty())
    throw std::runtime_error ("no filenames supplied when loading dataset");

  for (const auto& fname : filenames)
    m_slices.push_back (load_pgm (fname));

  // check that dimensions all match up:
  for (unsigned int n = 1; n < m_slices.size(); ++n) {
    if ( (m_slices[n].width() != m_slices[n-1].width()) ||
         (m_slices[n].height() != m_slices[n-1].height()) )
      throw std::runtime_error ("dimensions do not match across slices");
  }

  debug::log (std::format (
      "loaded {} slices of size {}x{}\n",
      m_slices.size(), m_slices[0].width(), m_slices[0].height()));
}





std::vector<int> Dataset::get_timecourse (int x, int y) const
{
  std::vector<int> vals (size());
  for (unsigned int n = 0; n < size(); ++n)
    vals[n] = m_slices[n].get(x,y);
  return vals;
}


