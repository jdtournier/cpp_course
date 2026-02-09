#include <iostream>
#include <string>

class TestClass {
  public:
    TestClass () : m_value (0) {
      std::cout << "TestClass default-constructed with values " << m_value << ", '" << m_label << "'\n";
    }

    TestClass (int value, const std::string& label) : m_value (value), m_label (label) {
      std::cout << "TestClass constructed with values " << m_value << ", '" << m_label << "'\n";
    }

    TestClass (const TestClass& other) : m_value (other.m_value), m_label (other.m_label) {
      std::cout << "TestClass copy-constructed with values " << m_value << ", '" << m_label << "'\n";
    }

    ~TestClass() {
      std::cout << "TestClass destroyed, held values " << m_value << ", '" << m_label << "'\n";
    }


  private:
    int m_value;
    std::string m_label;
};



int main ()
{
  TestClass a;
  TestClass b (3, "testing");

  TestClass c = b;

  return 0;
}
