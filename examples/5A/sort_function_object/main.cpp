#include <iostream>
#include <vector>
#include <algorithm>


// Overloaded stream insertion operator for vectors of ints:
inline std::ostream& operator<< (std::ostream& stream, const std::vector<int>& values)
{
  for (auto n : values)
    stream << n << " ";
  return stream;
}


// Simple function to use as predicate for sorting in reverse order:
inline bool comp (int a, int b) { return a > b; }


// Function object to check which of two arguments is closest to anchor value:
class DistanceComp {
  public:
    DistanceComp (int anchor) : m_anchor (anchor) { }
    bool operator() (int a, int b) const { return std::abs(a-m_anchor) < std::abs(b-m_anchor); }
  private:
    const int m_anchor;
};






int main ()
{
  std::vector<int> values;
  for (int n = 1; n <= 30; n++)
    values.push_back (n*n % 97);

  std::cout << "initial list: " << values << "\n";

  std::sort (values.begin(), values.end());
  std::cout << "sorted in ascending order: " << values << "\n";

  std::sort (values.begin(), values.end(), comp);
  std::cout << "sorted in descending order: " << values << "\n";

  std::sort (values.begin(), values.end(), DistanceComp(67));
  std::cout << "sorted in order of distance to 67: " << values << "\n";

  return 0;
}
