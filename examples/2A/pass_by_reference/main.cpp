#include <iostream>
#include <cmath>

void get_values_from_user (float& a, float &b, float& c)
{
  std::cout << "Please enter the lengths of the three sides of the triangle: ";
  std::cin >> a >> b >> c;
}

float compute_area_of_triangle (const float a, const float b, const float c)
{
  const float s = 0.5 * (a + b + c);
  return std::sqrt (s * (s-a) * (s-b) * (s-c));
}

int main ()
{
  float a, b, c;
  get_values_from_user(a, b, c);
  std::cout << "area = " << compute_area_of_triangle (a, b, c) << "\n";

  return 0;
}
