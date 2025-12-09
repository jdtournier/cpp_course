#include <iostream>
#include <cmath>

// define a struct to hold the values we need:
struct TriangleSides { float a, b, c; };

// and have this function return an instance of that struct:
TriangleSides get_values_from_user ()
{
  std::cout << "Please enter the lengths of the three sides of the triangle: ";
  TriangleSides s;
  std::cin >> s.a >> s.b >> s.c;
  return s;
}

float compute_area_of_triangle (const float a, const float b, const float c)
{
  const float s = 0.5 * (a + b + c);
  return std::sqrt (s * (s-a) * (s-b) * (s-c));
}

int main ()
{
  // now we can capture all 3 values in one return struct variable:
  auto s = get_values_from_user();

  // and use them in the next call:
  std::cout << "area = " << compute_area_of_triangle (s.a, s.b, s.c) << "\n";

  return 0;
}
