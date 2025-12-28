#pragma once

#include "particle.h"

class Electron : public Particle
{
    public:
        Electron() : Particle (0.00054875, -1.0) { }
};
