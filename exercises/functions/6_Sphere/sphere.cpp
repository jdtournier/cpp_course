#include "sphere.h"

float sphere (int r)
{
    float cube = r * r * r;
    return ((4.0 * pi * cube) / 3.0);
}
