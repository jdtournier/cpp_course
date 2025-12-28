#pragma once

class Particle
{
    public:
        Particle (float mass, float charge) : m_mass (mass), m_charge (charge) { }
        float get_mass() const { return m_mass; }
        float get_charge() const { return m_charge; }
    protected:
        const float m_mass;
        const float m_charge;
};
