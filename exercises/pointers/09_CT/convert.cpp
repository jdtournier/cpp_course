#include "convert.h"
#include "terminal_graphics.h"

TG::Image<float> convert_HU_to_AC (const TG::Image<int>& hu)
{
    TG::Image<float> ac (hu.width(), hu.height());
    for (int y = 0; y < hu.height(); y++)
        for (int x = 0; x < hu.width(); x++)
            ac(x,y) = HU_to_AC (hu(x,y));

    return ac;
}

