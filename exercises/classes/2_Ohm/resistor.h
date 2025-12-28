#pragma once

class Resistor
{
    public:
        Resistor() {};
        float get_R () const { return m_R; }
        void set_R (float val) { m_R = val; }
        float get_I (float V) const { return V/m_R;}
        float get_V (float I) const { return I*m_R;}
        float power (float I) const { return I*get_V(I);}
    private:
        float m_R;
};

