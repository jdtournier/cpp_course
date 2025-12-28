#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>

double model (double a, double b, double c)
{
    if (c <= -1.0)
        throw std::runtime_error ("c must be larger than -1");

    if (c == 0.0)
        throw std::runtime_error ("c must be non -zero");

    double x = a - b / std::log (c + 1.0);

    if (x < 0.0)
        throw std::runtime_error ("a must be larger than b/log(c+1)");

    return std::sqrt (x);
}

int main (int argc, char* argv[])
{
    std::vector<std::string> args (argv, argv+argc);
    if (args.size() < 4)
        throw std::runtime_error ("expected 3 floating-point arguments");

    try {
        double a = std::stod (args[1]);
        double b = std::stod (args[2]);
        double c = std::stod (args[3]);

        double value = model (a, b, c);

        std::cout << "result = " << value << "\n";
    }
    catch (const std::exception& error) {
        std::cerr << "error in calculation: " << error.what() << "\n";
    }
    catch (...) {
        std::cout << "unexpected error\n";
    }

    return 0;
}

