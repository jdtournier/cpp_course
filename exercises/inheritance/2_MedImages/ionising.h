#pragma once

#include "medicalimage.h"

class Ionising : public MedicalImage
{
    public:
        Ionising() {};
        float get_typical_dose() const { return m_typicalDose; }
        void set_typical_dose(float val) { m_typicalDose = val; }
        virtual void display() const = 0;
    protected:
        float m_typicalDose;
};
