#pragma once

#include <vector>

#include "nucleus.h"
#include "electron.h"

class Atom
{
    public:
        void set_electrons (int num) { m_e.resize (num); }
        void set_protons (int num) { m_nuc.set_protons (num); }
        void set_neutrons (int num) { m_nuc.set_neutrons (num); }
        int  get_atomic_number() const { return m_nuc.get_atomic_number(); }
        float get_mass() const {
            // compute mass of atom
            float m_totalMass = m_nuc.get_mass();
            for (int i = 0; i < m_e.size(); i++) // sum electrons' masses
                m_totalMass += m_e[i].get_mass();
            return m_totalMass;
        }
    private:
        Nucleus m_nuc;
        std::vector<Electron> m_e;
};
