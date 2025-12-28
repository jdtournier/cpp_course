#pragma once

#include <iostream>
#include "ionising.h"

class Xray : public Ionising
{
    public:
        Xray() {};
        void display() const { std::cout << "Xray display" << std::endl; }
    protected:
};
