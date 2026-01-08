#include <iostream>

int main()
{
  int x = 42;
  int* ptr = &x;

  std::cout << "x:    " << x   << "\n";  // value stored in x
  std::cout << "ptr:  " << ptr << "\n";  // address of x
  std::cout << "*ptr: " << *ptr << "\n"; // value at that address (42)

  return 0;
}
