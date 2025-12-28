#include <iostream>
#include <string>

#include "rlencode.h"

void rl_encode (const std::string& str)
{
    char c = str[0];
    int count = 1;
    for (unsigned int n = 1; n < str.size(); n++) {
        if (str[n] == c)
            count++;
        else {
            std::cout << static_cast<int>(c) << " " << count << " ";
            c = str[n];
            count = 1;
        }
    }
    std::cout << static_cast<int>(c) << " " << count << "\n";
}
