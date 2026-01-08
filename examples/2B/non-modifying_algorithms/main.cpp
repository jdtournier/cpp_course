#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Function to read integers until 'q' is entered
std::vector<int> read_vector()
{
  std::vector<int> v;
  std::string input;

  std::cout << "Enter integer values (press 'q' to stop):\n";

  while (true) {
    std::cout << "> ";
    std::cin >> input;

    if (input == "q")
      break;

    v.push_back (std::stoi (input));
  }

  return v;
}



int main()
{
  // Read values into the vector
  std::vector<int> data = read_vector();

  // Count how many times 4 appears
  std::cout << "The value 4 appears " << std::count (data.begin(), data.end(), 4) << " times." << std::endl;

  // Search for the first occurrence of 7
  auto it = find (data.begin(), data.end(), 7);
  if (it != data.end())
    std::cout << "The value 7 was found at index " << std::distance (data.begin(), it) << ".\n";
  else
    std::cout << "The value 7 was not found in the vector.\n";

  return 0;
}
