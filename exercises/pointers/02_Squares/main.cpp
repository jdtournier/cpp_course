#include <iostream>

// display squares of integers from 1 to 100
int main()
{
    int squares[100];

    // compute and store squares in array
    for (int i = 0; i < 100; i++)
        squares[i] = (i + 1) * (i + 1);

    // display array values
    for (int i = 0; i < 100; i++)
        std::cout << "The square of " << (i + 1)
             << " is " << squares[i] << "\n";

    return 0;
}
