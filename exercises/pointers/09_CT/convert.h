#pragma once

#include "terminal_graphics.h"


// convert single value from HU to AC
inline float HU_to_AC (float hu) {
    if (hu <= 0)
        return 0.093 + hu * 0.000093;
    else
        return 0.093 + hu * 0.000055031;
}

// convert from HU to AC for entire image
TG::Image<float> convert_HU_to_AC (const TG::Image<int>& im);

