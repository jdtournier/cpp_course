#pragma once

#include <iostream>

class Patient
{
    public:
        Patient(std::string fn, std::string ln) { m_firstName = fn; m_lastName = ln; }
        void set_name(std::string fn, std::string ln) { m_firstName = fn; m_lastName = ln; }
        void print() const {
          std::cout << std::endl << "Name: "
            << m_firstName << " " << m_lastName << std::endl;
        }
    protected:
        std::string m_firstName;
        std::string m_lastName;
};

class UrgentPatient: public Patient
{
    public:
        UrgentPatient (std::string fn, std::string ln, std::string r): Patient(fn, ln) { m_reason = r; }
        void set_reason (std::string r) { m_reason = r; }
        void print() const {
          Patient::print();
          std::cout << "URGENT: " << m_reason << std::endl;
        }
    protected:
        std::string m_reason;

};
