#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#include "fn.h"

int main (int argc, char* argv[])
{
    std::vector<std::string> args (argv, argv+argc);
    if (args.size() < 2)
        throw std::runtime_error ("expected floating-point value as argument");

    float x = std::stod (args[1]);

    float val = f(x);
    std::cout << "Value of expression = " << val << "\n";

    return 0;
}
