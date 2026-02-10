#include <array>
#include <string>
#include <vector>

struct ModuleMark {
  const std::string description;
  float mark, weighting;
};


enum class VisaStatus { Home, International, Visitor };

class Student {
  public:
    Student ();
    Student (const std::string& name, const std::array<int,3>& dob,
             int ID, VisaStatus visa = VisaStatus::Home);
    Student (const std::string& name, const std::array<int,3>& dob,
             int ID, const ModuleMark& module_mark, VisaStatus visa = VisaStatus::Home);

    int get_ID () const { return m_ID; }
    const std::string& get_name () const { return m_name; }
    float get_GPA () const { return m_GPA; }
    const std::array<int,3>& get_DOB () const { return m_dob; }
    VisaStatus get_visa_status () const { return m_visa; }

    void add_module_mark (const std::string& module_description, float mark, float weighting);

  private:
    int m_ID;
    std::string m_name;
    float m_GPA;
    std::array<int,3> m_dob;
    VisaStatus m_visa;
    std::vector<ModuleMark> m_marks;
};

