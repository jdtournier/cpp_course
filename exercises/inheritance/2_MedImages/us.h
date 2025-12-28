#pragma once

#include <iostream>

#include "nonionising.h"

class US : public NonIonising
{
    public:
        US() {};
        void display() const { std::cout << "US display" << std::endl; }
    protected:
};

