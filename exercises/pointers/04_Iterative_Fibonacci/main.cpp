#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#include "iter_fib.h"

int main(int argc, char* argv[])
{
    std::vector<std::string> args (argv, argv+argc);

    if (args.size() < 2)
        throw std::runtime_error ("expected number of Fibonacci numbers to print as argument");

    int n = std::stoi (args[1]);

    if ((n >= 2) && (n <= MAX_FIB))
        fibonacci_iter (n);
    else
        std::cerr << "Invalid number\n";

    return 0;
}
