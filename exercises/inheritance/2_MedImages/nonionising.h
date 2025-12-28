#pragma once

#include "medicalimage.h"

class NonIonising : public MedicalImage
{
    public:
        NonIonising() {};
        virtual void display() const = 0;
};

