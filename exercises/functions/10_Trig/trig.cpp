#include "trig.h"

const float small = 0.1;

float mysin (float x)
{
    if (x < small)
        return x - x * x * x / 6.0;

    float sin_term = mysin(x / 3.0);
    float tan_squared = mytan(x / 3.0);
    tan_squared *= tan_squared;
    float tan_denom = 3.0 - tan_squared;
    float tan_numer = 1.0 + tan_squared;
    return sin_term * tan_denom / tan_numer;
}

float mytan (float x) {
    return mysin(x) / mycos(x);
}

float mycos (float x) {

    return 1 - mysin(x / 2);
}

