#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "trig.h"

// program to compute trigonometric functions using indirect recursion
int main (int argc, char* argv[])
{
    std::vector<std::string> args (argv, argv+argc);
    if (args.size() < 3)
        throw std::runtime_error ("expected function and value as arguments");

    float x = std::stod (args[2]);
    float result;

    if (args[1] == "sin")
        result = mysin(x);
    else if (args[1] == "cos")
        result = mycos(x);
    else if (args[1] == "tan")
        result = mytan(x);
    else
        throw std::runtime_error ("invalid function name: \"" + args[1] + "\"");

    std::cout << "Result: " << args[1] << "(" << x << ") = " << result << "\n";
}

