#include <iostream>

#include "student.h"

int main ()
{
  Student s;

  s.init ("Jane Doe", { 3, 6, 2001 }, 2349423);

  s.add_module_mark ("mathematics", 3.2, 1.0);
  s.add_module_mark ("physics", 3.5, 2.0);
  s.add_module_mark ("intro to programming", 2.9, 1.0);
  s.add_module_mark ("signal processing", 3.7, 2.0);

  std::cout << "student: \"" << s.get_name() << "\", DOB: "
      << s.get_DOB()[0] << "/" << s.get_DOB()[1] << "/" << s.get_DOB()[2]
      << ", ID: " << s.get_ID() << ", GPA = " << s.get_GPA() << "\n";

  return 0;
}

