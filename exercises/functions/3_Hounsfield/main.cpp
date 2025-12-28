#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#include "convert.h"

int main (int argc, char* argv[])
{
    std::vector<std::string> args (argv, argv+argc);
    if (args.size() < 2)
        throw std::runtime_error ("expected value in HU as argument");

    float hu = std::stod (args[1]);

    std::cout << hu << " HU = " << HU_to_AC(hu) << " cm-1\n";

    return 0;
}
