#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

std::vector<int> load_data (const std::string& filename)
{
  std::ifstream infile (filename);
  if (!infile)
    throw std::runtime_error ("failed to open file \"" + filename + "\" for reading");

  int n;
  std::vector<int> data;
  while (infile >> n)
    data.push_back (n);

  return data;
}



int main(int argc, char* argv[])
{
  if (argc < 2)
    throw std::runtime_error ("expected at least one argument for filename of input file");

  auto data = load_data (argv[1]);

  std::cout << "Loaded data from \"" << argv[1] << "\" of size " << data.size() << "\n";

  return 0;
}
