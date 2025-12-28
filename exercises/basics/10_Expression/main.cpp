#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stdexcept>

int main (int argc, char* argv[])
{
    // Program to compute expression
    // using floating point arithmetic

    std::vector<std::string> args (argv, argv+argc);

    if (args.size() < 2)
      throw std::runtime_error ("expected one integer argument");

    int i = std::stoi (args[1]);

    // use decimal points in numbers to ensure
    // that floating-point arithmetic is used:
    float v = (i + 3.0) * (i + 2.0) * (i + 1.0) * i;
    float result = v * v * v;

    std::cout << "Result = " << result << "\n";
    return 0;
}
