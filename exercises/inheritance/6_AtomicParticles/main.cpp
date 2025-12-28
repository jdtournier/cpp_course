#include <iostream>

#include "atom.h"

int main()
{
    Atom helium;

    helium.set_electrons (2);
    helium.set_protons (2);
    helium.set_neutrons (2);

    std::cout << "Helium atom has mass " << helium.get_mass()
      << "u and atomic number " << helium.get_atomic_number() << std::endl;

    return 0;
}
