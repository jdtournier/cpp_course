#include <iostream>
#include <string>

int main()
{
  std::string name;

  // Prompt the user
  std::cout << "Enter a word: ";
  std::cin >> name;

  // Print the message using a single std::cout statement
  std::cout << "The word \"" << name << "\" contains "
    << name.size() << " characters.\n";

  return 0;
}
