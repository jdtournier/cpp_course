#pragma once

#include <cmath>

#include "energy.h"

class Kinetic : public Energy
{
    public:
        // note use of constructor chaining to initialise base class member
        Kinetic(float m, float v): Energy(m) { m_velocity = v; }
        float get_velocity() const { return m_velocity; }
        void set_velocity(float val) { m_velocity = val; }
        float compute_energy() const { return 0.5 * m_mass * m_velocity * m_velocity; }
    protected:
        float m_velocity;
};
