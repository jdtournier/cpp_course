#include <iostream>

#include "hanoi.h"

int main ()
{
    // move 3 disks from peg 1 to peg 3 using peg 2 as spare:
    tower (3, 1, 3, 2);
    return 0;
}
