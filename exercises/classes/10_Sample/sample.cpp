#include <iostream>
#include <cmath>
#include "sample.h"
using namespace std;

// initialise static lookup tables
float Sample::_swcoeff[9][5] = {
    {0.70071,0,     0,     0,     0     },
    {0.70071,0,     0,     0,     0     },
    {0.6872, 0.1677,0,     0,     0     },
    {0.6646, 0.2143,0,     0,     0     },
    {0.6431, 0.2806,0.0875,0,     0     },
    {0.6233, 0.3031,0.1401,0,     0     },
    {0.6052, 0.3164,0.1743,0.0561,0     },
    {0.5888, 0.3244,0.1976,0.0947,0     },
    {0.5739, 0.3291,0.2141,0.1224,0.0399}
};
float Sample::_swtab[8] = {0.767,0.748,0.762,0.788,0.803,0.818,0.829,0.842};

void Sample::SetSample(float val[], int n)
{
    _x.resize (n);
    for (int i = 0; i < n; i++)
        _x[i] = val[i];
}


float Sample::Mean() const
{
    float sum = 0.0;
    for (int i = 0; i < _x.size(); i++) {
        sum = sum + _x[i];
    }
    return sum/_x.size();
}


float Sample::StdDev() const
{
    float m = Mean();
    float s = 0;
    for (int i = 0; i < _x.size(); i++) {
        s = s + (_x[i] - m) * (_x[i] - m);
    }
    s = sqrt(s / (_x.size() - 1));
    return s;
}


void Sample::Display() const
{
    for (int i = 0; i < _x.size(); i++)
        cout << _x[i] << " ";
    cout << endl;
}


void Sample::Sort()
{
    //sort array using bubble sort algorithm
    for (int i = 0; i < _x.size(); i++) {
        for (int j = 0; j < _x.size() - 1; j++) {
            if (_x[j] > _x[j+1]) { // swap values
                float temp = _x[j];
                _x[j] = _x[j+1];
                _x[j+1] = temp;
            }
        }
    }
}


// perform Shapiro-Wilk test on sample
bool Sample::ShapiroWilk()
{
    // rank data
    Sort();

    // compute b
    float b = 0, diff;
    for (int i = 0; i < _x.size() / 2; i++) {
        diff = _x[_x.size() - i - 1] - _x[i];
        b = b + (diff) * _swcoeff[_x.size() - 2][i];
    }

    // compute test statistic
    float s = StdDev();
    float calcw = (b * b) / ((_x.size() - 1) * s * s);

    // look up critical value
    float tabw = _swtab[_x.size() - 3];

    // test hypothesis
    if (calcw > tabw)
        return true; // do not reject null hypothesis that sample is normal
    else
        return false;  // reject the null hypothesis - it's not normal
}
