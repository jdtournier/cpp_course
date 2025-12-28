#include <iostream>

#include "reverse.h"

void reverse ()
{
    char ch;
    std::cin.get(ch);
    if (ch != '\n') {
        reverse ();
        std::cout.put(ch);
    }
}
