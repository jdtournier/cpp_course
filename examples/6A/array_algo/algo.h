#pragma once

template <typename ArrayType> double get_mean (const ArrayType& array)
{
  double sum = 0.0;
  for (int j = 0; j < array.size(1); ++j)
    for (int i = 0; i < array.size(0); ++i)
      sum += array(i,j);
  return sum / (array.size(0)*array.size(1));
}

