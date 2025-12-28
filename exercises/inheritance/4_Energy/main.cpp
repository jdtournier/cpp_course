#include <iostream>

#include "potential.h"
#include "kinetic.h"

int main()
{
    // potential: read mass, height
    float m, h;
    std::cout << "Enter mass: ";
    std::cin >> m;
    std::cout << "Enter height: ";
    std::cin >> h;
    Potential p(m, h, 9.8);
    std::cout << m << "kg object raised " << h << "m has potential energy " << p.compute_energy() << "J" << std::endl;

    // kinetic: read velocity
    float v;
    std::cout << "Enter velocity: ";
    std::cin >> v;
    Kinetic k(m, v);
    std::cout << m << "kg object moving at " << v << "m/s has kinetic energy " << k.compute_energy() << "J" << std::endl;


    return 0;
}
