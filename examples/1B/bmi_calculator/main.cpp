#include <iostream>

int main()
{
  float w, h;
  std::cout << "Please enter your weight (in kg) and height (in meters): ";
  std::cin >> w >> h;

  if (w < 20.0 || w > 300.0 || h < 0.5 || h > 2.5)
    std::cout << "WARNING: one or both values entered are out of range\n";

  float bmi = w/(h*h);
  std::cout << "Your BMI is " << bmi << ", which falls into category: ";

  if (bmi < 18.5)
    std::cout << "underweight\n";
  else if (18.5 <= bmi && bmi < 25.0)
    std::cout << "healthy\n";
  else if (25.0 <= bmi && bmi < 30.0)
    std::cout << "overweight\n";
  else if (bmi <= 30.0)
    std::cout << "obese\n";

  return 0;
}
