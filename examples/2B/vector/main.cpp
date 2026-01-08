#include <iostream>
#include <vector>

int main()
{
  std::vector<int> values;

  // Prompt the user to enter values:
  std::cout << "Enter integer values (enter the value '0' to end): ";

  // read values in until user enters zero:
  int val;
  while (std::cin >> val && val != 0)
    values.push_back (val);

  // Compute sum and product:
  int sum = 0;
  int product = 1;

  for (int v : values) {
    sum += v;
    product *= v;
  }

  // Report results:
  std::cout << "Number of elements: " << values.size() << "\n";
  std::cout << "Sum: " << sum << "\n";
  std::cout << "Product: " << product << "\n";

  return 0;
}
