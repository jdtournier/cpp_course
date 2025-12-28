#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "rlencode.h"

// program to perform run -length encoding on string
int main (int argc, char* argv[])
{
    std::vector<std::string> args (argv, argv+argc);
    if (args.size() < 2)
        throw std::runtime_error ("expected string as argument");

    rl_encode (args[1]);

    return 0;
}
