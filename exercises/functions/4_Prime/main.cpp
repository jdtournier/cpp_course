#include <iostream>
#include <vector>
#include <string>

#include "prime.h"

int main (int argc, char* argv[])
{
    std::vector<std::string> args (argv, argv+argc);
    int num = 50;
    if (args.size() > 1)
        num = std::stoi (args[1]);

    display_primes (num);

    return 0;
}
