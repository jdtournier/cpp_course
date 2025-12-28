#pragma once

#include "energy.h"

class Potential: public Energy
{
    public:
        // note use of constructor chaining to initialise base class member
        Potential(float m, float h, float g): Energy(m) { m_height = h; m_gravity = g; }
        float get_height() const { return m_height; }
        void set_height(float val) { m_height = val; }
        float get_gravity() const { return m_gravity; }
        void set_gravity(float val) { m_gravity = val; }
        float compute_energy() const { return m_mass * m_gravity * m_height; }
    protected:
        float m_height;
        float m_gravity;
};
