#include <iostream>
#include <fstream>
#include <string>

int main()
{
  std::string filename = "data.txt";

  std::ifstream infile (filename);
  if (!infile) {
    std::cerr << "ERROR: failed to open file \"" << filename << "\" for reading - aborting\n";
    return 1;    // <- we return from main() with a non-zero exit code
  }

  std::cout << "File \"" << filename << "\" opened successfully\n";

  double sum = 0.0;
  int count = 0;

  int n;
  while (infile >> n) {
    sum += n;
    count++;
  }

  std::cout << "Mean value computed from file \"" << filename << "\" = " << sum/count << "\n";

  return 0;
}
