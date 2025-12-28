#pragma once

#include <string>

class Town
{
    public:
        Town();
        std::string Getname() const { return m_name; }
        void set_name (std::string val) { m_name = val; }
        int get_population () const { return m_population; }
        void set_population (int val) { m_population = val; }
        bool get_airport () const { return m_airport; }
        void set_airport (bool val) { m_airport = val; }
        void print() const;
    private:
        std::string m_name;
        int m_population;
        bool m_airport;
};

