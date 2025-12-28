#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "palindrome.h"

int main(int argc, char* argv[])
{
    std::vector<std::string> args (argv, argv+argc);

    if (args.size() < 2)
        throw std::runtime_error ("expected word to check as argument");

    if (is_palindrome (args[1]))
        std::cout << "\"" << args[1] << "\" is a palindrome!\n";
    else
        std::cout << "\"" << args[1] << "\" is not a palindrome\n";

    return 0;
}
