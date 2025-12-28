#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stdexcept>

int main (int argc, char* argv[])
{
    std::vector<std::string> args (argv, argv+argc);

    if (args.size() < 4)
      throw std::runtime_error ("expected 3 arguments");

    double x = std::stod (args[1]);
    double y = std::stod (args[2]);
    double z = std::stod (args[3]);

    double result = std::pow (x, std::pow (y,z));
    std::cout << "x^y^z = " << result << "\n";

    return 0;
}

