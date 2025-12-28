#include <iostream>
#include <cmath>
#include "sample.h"
using namespace std;


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
    // alternative implementation:
    // #include <algorithm>
    // std::sort (_x.begin(), _x.end());

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
