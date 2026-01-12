#include <array>
#include <string>
#include <vector>

struct ModuleMark {
  const std::string description;
  float mark, weighting;
};


class Student {
  public:
    int get_ID () const { return m_ID; }
    const std::string& get_name () const { return m_name; }
    float get_GPA () const { return m_GPA; }
    const std::array<int,3>& get_DOB () const { return m_dob; }

    void init (const std::string& name, const std::array<int,3>& dob, int ID) {
      m_name = name;
      m_ID = ID;
      m_dob = dob;
      m_GPA = 0.0;
    }

    void add_module_mark (const std::string& module_description, float mark, float weighting);

    friend std::ostream& operator<< (std::ostream& stream, const Student& s);

  private:
    int m_ID = 0;
    std::string m_name;
    float m_GPA = 0.0;
    std::array<int,3> m_dob = { 0, 0, 0 };
    std::vector<ModuleMark> m_marks;
};


