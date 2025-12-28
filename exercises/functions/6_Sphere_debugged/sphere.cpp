#include "sphere.h"

double sphere (double r)
{
    const double pi = 3.14159265;

    double cube = r * r * r;
    return ((4.0 * pi * cube) / 3.0);
}
