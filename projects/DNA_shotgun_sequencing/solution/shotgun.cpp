#include <iostream>

int main (int argc, char* argv[])
{
  if (argc < 2) {
    std::cerr << "ERROR: expected filename as first argument\n";
    return 1;
  }
  std::cerr << "reading fragments from file \"" << argv[1] << "\"...\n";

  return 0;
}
