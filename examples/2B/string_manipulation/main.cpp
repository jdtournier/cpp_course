#include <iostream>
#include <string>

int main()
{
  std::string filename;

  // Prompt the user
  std::cout << "Enter a filename: ";
  std::cin >> filename;

  // Check if the filename ends with ".txt"
  if (filename.ends_with (".txt")) {

    // Remove the ".txt" suffix
    std::string baseName = filename.substr(0, filename.size() - 4);
    std::cout << "Filename without extension: " << baseName << "\n";
  }
  else {
    std::cout << "The filename does not end with .txt\n";
  }

  return 0;
}
