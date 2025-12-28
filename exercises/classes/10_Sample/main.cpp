#include <iostream>
#include "sample.h"
using namespace std;

int main()
{
    float a[8] = {18.44,14.18,19.79,15.73,15.36,16.17,13.91,15.35};
    Sample samp;
    samp.SetSample(a, 8); samp.Display();
    cout << "Sample mean = " << samp.Mean() << endl;
    cout << "Sample std dev = " << samp.StdDev() << endl;
    cout << "Shapiro-Wilk test result = " << samp.ShapiroWilk() << endl;
    return 0;
}
