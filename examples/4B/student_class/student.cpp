#include <iostream>

#include "student.h"

Student::Student () :
  m_ID (0), m_GPA (0.0), m_dob ({ 0,0,0 }), m_visa (VisaStatus::Home) { }

Student::Student (const std::string& name, const std::array<int,3>& dob,
                  int ID, VisaStatus visa) :
  m_ID (ID), m_name (name), m_GPA (0.0), m_dob (dob), m_visa (visa) { }

Student::Student (const std::string& name, const std::array<int,3>& dob,
                  int ID, const ModuleMark& module_mark, VisaStatus visa) :
  Student (name, dob, ID, visa) {
    m_marks.push_back (module_mark);
  }

void Student::add_module_mark (const std::string& module_description,
                               float mark, float weighting)
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

