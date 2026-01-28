#pragma once

template <typename ArrayType> double get_mean (const ArrayType& array)
{
  double sum = 0.0;
  for (int j = 0; j < array.size(1); ++j)
    for (int i = 0; i < array.size(0); ++i)
      sum += array(i,j);
  return sum / (array.size(0)*array.size(1));
}

template <typename ArrayType> ArrayType transpose (const ArrayType& A)
{
  ArrayType B (A.size(1), A.size(0));
  for (int j = 0; j < A.size(1); ++j)
    for (int i = 0; i < A.size(0); ++i)
      B(j,i) = A(i,j);
  return B;
}

template <typename ArrayType, typename OpType>
void for_each (ArrayType& A, const OpType& op)
{
  for (int j = 0; j < A.size(1); ++j)
    for (int i = 0; i < A.size(0); ++i)
      A(j,i) = op (A(i,j));
}

