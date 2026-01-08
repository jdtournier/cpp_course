#include <iostream>
#include <vector>

// Function that prompts the user for the size and elements of the vector:
std::vector<int> read_vector()
{
  std::cout << "Enter the size of the vector: ";
  int n;
  std::cin >> n;

  std::vector<int> v (n);
  for (int i = 0; i < v.size(); ++i) {
    std::cout << "Enter element " << i << ": ";
    std::cin >> v[i];
  }

  return v;
}

// Function that returns the product of the elements of a vector:
int compute_product (const std::vector<int>& v)
{
  int prod = 1;
  // Range-based loop: only values are needed
  for (int x : v)
    prod *= x;

  return prod;
}

// Function that returns the index of the minimum element:
int index_of_mininum (const std::vector<int>& v)
{
  int min_index = 0;
  // Regular for loop: index is required
  for (int i = 1; i < v.size(); ++i)
    if (v[i] < v[min_index])
      min_index = i;

  return min_index;
}



int main()
{
  // Create the vector using the input function
  std::vector<int> data = read_vector();

  // compute and print results:
  std::cout << "Product of elements: " << compute_product (data) << "\n";
  std::cout << "Index of minimum element: " << index_of_mininum (data) << "\n";

  return 0;
}

