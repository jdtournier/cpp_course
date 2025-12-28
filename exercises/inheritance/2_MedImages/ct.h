#pragma once

#include <iostream>

#include "ionising.h"

class CT : public Ionising
{
    public:
        CT() {};
        void display() const { std::cout << "CT display" << std::endl; }
    protected:
};

