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
      throw std::runtime_error ("expected one floating-point argument");

    float r = std::stod (args[1]);

    // compute area , vol
    float area = 4.0 * M_PI * r * r;
    float vol = (4.0 / 3.0) * M_PI * r * r * r;

    // display to terminal:
    std::cout << "Surface area = " << area << "\n";
    std::cout << "Volume = " << vol << "\n";

    return 0;
}

