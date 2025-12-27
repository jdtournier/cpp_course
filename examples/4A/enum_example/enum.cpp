#include <iostream>

enum MaritalStatus {
  Single,
  Married,
  Widowed,
  Divorced
};

enum ProbeType {
  //Single,   // <- raises an error due to a naming conflict!
  Twin,
  Complex,
  Array
};

int main ()
{
  ProbeType p = Twin;
  MaritalStatus m = Single;

  if (p == m)   // <- raises a warning, but compiles anyway!
    std::cout << "match\n";
  else
    std::cout << "no match\n";

  // We get a match here, since the two values are the first ones listed in
  // their respective enums, and so will by default map to the same integer
  // representation. But this of course makes absolutely no sense: how can we
  // compare marital status with the type of imaging probe?!?

  return 0;
}

