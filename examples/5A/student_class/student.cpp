#include <iostream>

#include "student.h"

void Student::add_module_mark (const std::string& module_description, float mark, float weighting)
{
  // add marks for this module to the list:
  m_marks.push_back ({ module_description, mark, weighting });

  // update the computed GPA:
  double total_weight = 0.0;
  double total_sum = 0.0;
  for (const auto& m : m_marks) {
    total_weight += m.weighting;
    total_sum += m.weighting * m.mark;
  }

  m_GPA = total_sum / total_weight;
}




std::ostream& operator<< (std::ostream& stream, const Student& s)
{
  stream << "student: \"" << s.get_name() << "\", DOB: "
      << s.get_DOB()[0] << "/" << s.get_DOB()[1] << "/" << s.get_DOB()[2]
      << ", ID: " << s.get_ID() << ", GPA = " << s.get_GPA();
  return stream;
}
