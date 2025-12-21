#include <iostream>

float get_valid_value_from_user ()
{
  while (true) {
    std::cout << "Please enter a value between 5 & 100: ";
    float value;
    std::cin >> value;
    if (value >= 5.0 && value <= 100.0)
      return value;
    std::cout << "ERROR: value is not within bounds\n";
  }
}

int main ()
{
  float value = get_valid_value_from_user();
  std::cout << "Value = " << value << "\n";

  return 0;
}
