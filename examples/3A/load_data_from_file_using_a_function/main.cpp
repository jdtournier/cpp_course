#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> load_data (const std::string& filename)
{
  std::vector<int> data;

  std::ifstream infile (filename);
  if (!infile) {
    std::cerr << "ERROR: failed to open file \"" << filename << "\" for reading - aborting\n";
    return data;
  }

  int n;
  while (infile >> n)
    data.push_back (n);

  return data;
}



int main()
{
  std::string filename = "data.txt";

  auto data = load_data (filename);

  std::cout << "Loaded " << data.size() << " entries from the file \"" << filename << "\"\n";

  return 0;
}
