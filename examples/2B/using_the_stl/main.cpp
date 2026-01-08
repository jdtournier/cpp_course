#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

std::vector<int> read_from_terminal()
{
  std::cout << "Please enter numbers (enter negative number to end): ";

  std::vector<int> v;
  while (true) {
    int value;
    std::cin >> value;
    if (value < 0)
      break;
    v.push_back(value);
  }

  return v;
}



void print_vector (const std::vector<int>& v)
{
  for (auto elem : v)
    std::cout << elem << " ";
  std::cout << "\n";
}


float average (const std::vector<int>& v)
{
  int sum = 0;
  for (auto elem : v)
    sum += elem;
  std::cerr << sum << " " << v.size() << " " << float(sum)/v.size() << "\n";

  return float(sum)/v.size();
}


int main()
{
  auto numbers = read_from_terminal();

  if (numbers.empty()) {
    std::cerr << "No numbers to process.\n";
    return 1;
  }

  // Sort ascending and print
  std::sort (numbers.begin(), numbers.end());
  std::cout << "Ascending order: ";
  print_vector (numbers);

  // Sort descending and print
  std::reverse (numbers.begin(), numbers.end());
  std::cout << "Descending order: ";
  print_vector (numbers);

  // Remove elements below average:
  double av = average (numbers);
  std::cout << "Average: " << av << "\n";
  for (int n = numbers.size()-1; n>=0; n--)
    if (numbers[n] < av)
      numbers.erase (numbers.begin()+n);
  print_vector (numbers);

  return 0;
}
