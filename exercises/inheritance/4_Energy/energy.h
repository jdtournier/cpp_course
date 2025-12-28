#pragma once

class Energy
{
    public:
        Energy(float m) { m_mass = m; }
        float get_mass() const { return m_mass; }
        void set_mass(float val) { m_mass = val; }
        virtual float compute_energy()  const = 0;
    protected:
        float m_mass;
};
