#include <iostream>
#include <fstream>
#include <string>

int main()
{
  std::string filename = "data_out.txt";

  std::ofstream outfile (filename);
  if (!outfile) {
    std::cerr << "ERROR: failed to open file \"" << filename << "\" for writing - aborting\n";
    return 1;
  }

  outfile << "The demonstration code successfully wrote this line to the file \"" << filename << "\"\n";

  return 0;
}
