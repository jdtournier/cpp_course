#include <iostream>
#include <termviz.h>

#include "image.h"

// helper function to simplify subsequent code:
void display (const Image& a, const std::string& label, int min, int max)
{
  std::cout << label << " (range [ " << min << " " << max << " ]):\n";
  termviz::imshow (a, min, max);
}



int main ()
{
  Image a (128,128);
  for (int j = 0; j < a.height(); j++)
    for (int i = 0; i < a.width(); i++)
      a(i,j) = i;
  display (a, "a", 0, 128);

  Image b (128,128);
  for (int j = 0; j < b.height(); j++)
    for (int i = 0; i < b.width(); i++)
      b(i,j) = j;
  display (b, "b", 0, 128);

  display (a+b, "a+b", 0, 256);
  display (a-b, "a-b", -128, 128);
  display (a*b, "a*b", 0, 128*128);

  display (256-a, "256-a", 0, 256);
  display (a*2, "a*2", 0, 256);
  display (a/(b+1), "a/(b+1)", 0, 16);
  display (a+256-2*b, "a+256-2*b", 0, 256);

  return 0;
}
