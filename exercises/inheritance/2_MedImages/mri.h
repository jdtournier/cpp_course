#pragma once

#include <iostream>

#include "nonionising.h"

class MRI : public NonIonising
{
    public:
        MRI() {};
        void display() const { std::cout << "MRI display" << std::endl; }
    protected:
};
