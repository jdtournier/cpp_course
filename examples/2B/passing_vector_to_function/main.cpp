#include <iostream>
#include <vector>

// Function that computes and returns the mean value of a vector of integers
double compute_mean (const std::vector<int>& v)
{
  int sum = 0;

  for (int x : v)
    sum += x;

  // we need to cast 'sum' to a double, otherwise this will use integer
  // division:
  return static_cast<double>(sum) / v.size();
}



int main()
{
  // Declare and initialise the vector:
  std::vector<int> data = {1, 2, 3, 4};

  // Compute and print the result:
  std::cout << "Mean value: " << compute_mean (data) << "\n";

  return 0;
}
