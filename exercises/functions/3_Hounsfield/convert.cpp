#include <iostream>
#include "convert.h"

float HU_to_AC (float hu)
{
    if (hu <= 0.0)
        return 0.093 + hu * 0.000093;
    else
        return 0.093 + hu * 0.000055031;
}
