#include "fn.h"

float f (float x)
{
    float result;
    result = x * x * x;
    result -= 5.0 * x * x;
    result += 12.0 * x;
    result -= 24.0;
    return result;
}

