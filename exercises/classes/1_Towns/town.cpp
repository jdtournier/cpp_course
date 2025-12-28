#include <iostream>

#include "town.h"

Town::Town() :
    m_population (0),
    m_airport (false) { }

void Town::print() const
{
    std::cout << "----------\n";
    std::cout << "Name: " << m_name << "\n";
    std::cout << "Population: " << m_population << "\n";
    if (m_airport)
        std::cout << "Has airport\n";
    else
        std::cout << "Does not have airport\n";
    std::cout << "----------\n";
}

