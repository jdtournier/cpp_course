#include <iostream>
#include <termviz.h>

#include "image.h"

// helper function to simplify subsequent code:
template <typename T>
void display (const Image<T>& a, const std::string& label, int min, int max)
{
  std::cout << label << " (range [ " << min << " " << max << " ]):\n";
  termviz::imshow (a, min, max);
}






int main ()
{
  Image<short> a (128,128);
  for (int j = 0; j < a.height(); j++)
    for (int i = 0; i < a.width(); i++)
      a(i,j) = i;
  display (a, "a", 0, 128);


  Image<short> b (128,128);
  for (int j = 0; j < b.height(); j++)
    for (int i = 0; i < b.width(); i++)
      b(i,j) = j;
  display (b, "b", 0, 128);


  display (a+b, "a+b", 0, 256);
  display (a-b, "a-b", -128, 128);
  display (a*b, "a*b", 0, 128*128);


  return 0;
}
