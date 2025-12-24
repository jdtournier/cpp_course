#include <array>
#include <string>

class Student {
    int m_ID = 0;
    std::string m_name;
    float m_GPA = 0.0;
    std::array<int,3> m_dob = { 0, 0, 0 };
};

int main ()
{
  Student s;

  return 0;
}

