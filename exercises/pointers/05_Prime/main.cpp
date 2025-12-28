#include <iostream>
#include <vector>

bool is_prime (int n, const std::vector<int>& list)
{
    for (unsigned int i = 0; i < list.size(); i++)
        if ((n % list[i]) == 0)
            return false;
    return true;
}

int main (int argc, char* argv[])
{
    std::vector<std::string> args (argv, argv+argc);

    if (args.size() < 2)
        throw std::runtime_error ("expected maximum prime as argument");

    // get maximum number from user:
    unsigned int max_prime = std::stoi (args[1]);

    // build up vector of prime numbers:
    std::vector<int> prime_list { 2 };
    for (unsigned int n = 3; n < max_prime; n++)
        if (is_prime (n, prime_list))
            prime_list.push_back (n);

    // report number and values of prime numbers found:
    std::cout << "found " << prime_list.size() << " prime numbers:\n";
    for (unsigned int n = 0; n < prime_list.size(); n++)
        std::cout << prime_list[n] << " ";
    std::cout << "\n";

    return 0;
}


