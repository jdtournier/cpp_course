#include <iostream>

#include "hanoi.h"

void tower (int n, int from, int to, int spare)
{
    if (n == 1) // anchor condition
        std::cout << "move disk from peg " << from << " to peg " << to << "\n";
    else { // inductive step
        tower (n - 1, from , spare , to);
        std::cout << "move disk from peg " << from << " to peg " << to << "\n";
        tower (n - 1, spare , to , from );
    }
}
