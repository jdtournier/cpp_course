#include <array>
#include <string>
#include <vector>

struct ModuleMark {
  const std::string description;
  float mark, weighting;
};


class Student {
  public:
    Student () : m_ID (0), m_GPA (0.0), m_dob ({ 0,0,0 }) { }
    Student (const std::string& name, const std::array<int,3>& dob, int ID) :
      m_ID (ID), m_name (name), m_GPA (0.0), m_dob (dob) { }

    Student (const std::string& name, const std::array<int,3>& dob, int ID, const ModuleMark& module_mark) :
      Student (name, dob, ID) {
        m_marks.push_back (module_mark);
      }

    int get_ID () const { return m_ID; }
    const std::string& get_name () const { return m_name; }
    float get_GPA () const { return m_GPA; }
    const std::array<int,3>& get_DOB () const { return m_dob; }

    void add_module_mark (const std::string& module_description, float mark, float weighting);

  private:
    int m_ID;
    std::string m_name;
    float m_GPA;
    std::array<int,3> m_dob;
    std::vector<ModuleMark> m_marks;
};

