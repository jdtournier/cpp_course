#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stdexcept>

int main (int argc, char* argv[])
{
    std::vector<std::string> args (argv, argv+argc);

    if (args.size() < 2)
      throw std::runtime_error ("expected at least one argument");

    int n = std::stoi (args[1]);
    std::cout << "result = " << std::sqrt (std::abs (n)) << "\n";

    return 0;
}
