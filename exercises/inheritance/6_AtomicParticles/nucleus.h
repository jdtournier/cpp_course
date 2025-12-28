#pragma once

#include <vector>

#include "proton.h"
#include "neutron.h"

class Nucleus
{
    public:
        void set_protons (int num) { m_p.resize (num); }
        void set_neutrons (int num) { m_n.resize (num); }
        int get_atomic_number() const { return m_p.size(); }
        float get_mass() const {
            // compute mass of nucleus
            float m_totalMass = 0.0;
            for (int i = 0; i < m_p.size(); i++) //sum masses of protons
                m_totalMass += m_p[i].get_mass();
            for (int i = 0; i < m_n.size(); i++) // sum masses of neutrons
                m_totalMass += m_n[i].get_mass();
            return m_totalMass;
        }
    private:
        std::vector<Neutron> m_n;
        std::vector<Proton> m_p;
};
