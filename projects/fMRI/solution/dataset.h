#pragma once

#include <vector>
#include <string>
#include <format>

#include "image.h"
#include "pgm.h"
#include "debug.h"

template <typename ValueType>
class Dataset
{
  public:
    Dataset () = default;
    Dataset (const std::vector<std::string>& filenames) { load (filenames); }

    void load (const std::vector<std::string>& filenames);

    unsigned int size () const { return m_slices.size(); }

    Image<ValueType>&       operator[] (int n)       { return m_slices[n]; }
    const Image<ValueType>& operator[] (int n) const { return m_slices[n]; }

    std::vector<ValueType> get_timecourse (int x, int y) const;

  private:
    std::vector<Image<ValueType>> m_slices;
};


template <typename ValueType>
inline std::ostream& operator<< (std::ostream& out, const Dataset<ValueType>& data)
{
  out << "Data set with " << data.size() << " images:\n";
  for (unsigned int n = 0; n < data.size(); ++n)
    out << "  image " << n << ": " << data[n] << "\n";
  return out;
}




template <typename ValueType>
void Dataset<ValueType>::load (const std::vector<std::string>& filenames)
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





template <typename ValueType>
std::vector<ValueType> Dataset<ValueType>::get_timecourse (int x, int y) const
{
  std::vector<ValueType> vals (size());
  for (unsigned int n = 0; n < size(); ++n)
    vals[n] = m_slices[n](x,y);
  return vals;
}


