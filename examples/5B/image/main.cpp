#include <iostream>
#include <format>

#include "image.h"

// function to display all the values in the image - for testing:
void print (const Image& a, const std::string& label = {})
{
  std::cout << std::format ("{:-<80s}\n", ""); // print a line: 80 '-'
  if (label.size()) {
    std::cout << "  " << label << ":\n";
    std::cout << std::format ("{:-<80s}\n", ""); // print a line: 80 '-'
  }
  for (int j = 0; j < a.height(); j++) {
    for (int i = 0; i < a.width(); i++)
      std::cout << std::format ("{:>3} ", a(i,j));
    std::cout << "\n";
  }
  std::cout << std::format ("{:-<80s}\n", ""); // print a line: 80 '-'
}


int main ()
{
  Image a;
  std::cout << "Image a: " << a << "\n";

  Image b (10,10);
  std::cout << "Image b: " << b << "\n";

  std::cout << "a == b: " << (a==b) << "\n";
  std::cout << "a != b: " << (a!=b) << "\n";

  auto c = b;

  std::cout << "b == c: " << (b==c) << "\n";
  std::cout << "b != c: " << (b!=c) << "\n";

  c(1,1) = 1;

  std::cout << "b == c: " << (b==c) << "\n";
  std::cout << "b != c: " << (b!=c) << "\n";

  a.resize (10,10);
  std::cout << "Image a: " << a << "\n";

  std::cout << "a<b: " << (a<b) << "\n";
  std::cout << "a<=b: " << (a<=b) << "\n";
  std::cout << "a>b: " << (a>b) << "\n";
  std::cout << "a>=b: " << (a>=b) << "\n";

  std::cout << "c<1:" << (c<1) << "\n";
  std::cout << "c<=1: " << (c<=1) << "\n";
  std::cout << "1>c: " << (1>c) << "\n";
  std::cout << "1>=c: " << (1>=c) << "\n";

  a(2,2) = 2;
  c(2,2) = -3;
  c(2,1) = 3;
  a(1,2) = 4;
  a(1,1) = 5;
  print (a, "a");
  print (c, "c");

  print (a+c, "a+c");
  print (a-c, "a-c");
  print (a*c, "a*c");
  print (a/c, "a/c"); // <- crashes with divide by zero floating-point exception!

  return 0;
}
