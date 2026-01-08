#include <iostream>
#include <array>
#include <cmath>

// Function to compute the root mean square value of an array of 5 ints:
double compute_rms (const std::array<int,5>& arr)
{
    int sum = 0;

    for (int x : arr)
      sum += x*x;

    return std::sqrt (sum / static_cast<double>(arr.size()));
}


int main()
{
    // Declare and initialise the array:
    std::array<int,5> data = {1, 2, 3, 4, 5};


    // compute and print the root mean square value:
    std::cout << "Root mean square value = " << compute_rms (data) << "\n";

    return 0;
}
