#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
  std::string filename = "data.txt";

  std::ifstream infile (filename);
  if (!infile) {
    std::cerr << "ERROR: failed to open file \"" << filename << "\" for reading - aborting\n";
    return 1;    // <- we return from main() with a non-zero exit code
  }

  std::cout << "File \"" << filename << "\" opened successfully\n";

  std::vector<int> data;

  int n;
  while (infile >> n)
    data.push_back (n);

  std::cout << "Loaded " << data.size() << " entries from the file \"" << filename << "\"\n";

  return 0;
}
