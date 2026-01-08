#include <iostream>
#include <string>
#include <format>

int main()
{
  std::string name = "joe";
  int age = 26;
  float weight = 68.3;
  double result = 0.02342;

  std::cout << "Using std::cout directly:\n";
  std::cout << "Patient " << name << " (age " << age << ", weight " << weight << "kg): result = " << result << "\n\n";

  std::cout << "Using string concatenation:\n";
  std::string output = "Patient " + name + " (age " + std::to_string(age)
    + ", weight " + std::to_string(weight) + "kg): result = " + std::to_string(result);
  std::cout << output << "\n\n";

  std::cout << "Using std::format():\n";
  output = std::format ("Patient {} (age {}, weight {}kg): result = {}", name, age, weight, result);
  std::cout << output << "\n\n";

  return 0;
}
