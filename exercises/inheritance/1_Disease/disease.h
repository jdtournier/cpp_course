#pragma once

#include <string>

class Disease
{
    public:
        Disease() {};
        void set_description(std::string val) {m_description = val; }
        std::string get_description() const { return m_description; }
    protected:
        std::string m_description;
};