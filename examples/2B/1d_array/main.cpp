#include <iostream>

int main()
{
  int myArray[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  std::cout << "Array contents using regular for loop:\n";
  for (int i = 0; i < 9; i++)
    std::cout << "myArray" << i << "] = " << myArray[i] << "\n";
  std::cout << "\n";

  int sum = 0;
  for (int value : myArray)
    sum += value;
  std::cout << "Sum computed using range-based for loop: " << sum << "\n";

  return 0;
}
