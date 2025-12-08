#include <iostream>

enum class MaritalStatus {
  Single,
  Married,
  Widowed,
  Divorced
};

enum class ProbeType {
  Single,  // <- this is no longer a problem: it's in a different scope
  Twin,
  Complex,
  Array
};

int main ()
{
  ProbeType p = ProbeType::Single;
  MaritalStatus m = MaritalStatus::Single;

  if (p == m)   // <- this now raises a error, and the program cannot compile
    std::cout << "match\n";
  else
    std::cout << "no match\n";

  return 0;
}

