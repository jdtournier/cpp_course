#include <array>
#include <string>
#include <iostream>

class Student {
  public:
    int get_ID () const { return m_ID; }
    const std::string& get_name () const { return m_name; }
    float get_GPA () const { return m_GPA; }
    const std::array<int,3>& get_DOB () const { return m_dob; }

    void init (const std::string& name, const std::array<int,3>& dob, int ID, float GPA = 0.0) {
      m_name = name;
      m_ID = ID;
      m_dob = dob;
      m_GPA = GPA;
    }

    void set_GPA (float GPA) { m_GPA = GPA; }

  private:
    int m_ID = 0;
    std::string m_name;
    float m_GPA = 0.0;
    std::array<int,3> m_dob = { 0, 0, 0 };
};

int main ()
{
  Student s;

  s.init ("Jane Doe", { 3, 6, 2001 }, 2349423, 3.8);

  std::cout << "student: \"" << s.get_name() << "\", DOB: "
      << s.get_DOB()[0] << "/" << s.get_DOB()[1] << "/" << s.get_DOB()[2]
      << ", ID: " << s.get_ID() << ", GPA = " << s.get_GPA() << "\n";

  return 0;
}

