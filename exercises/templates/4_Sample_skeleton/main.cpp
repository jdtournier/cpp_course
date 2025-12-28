#include <iostream>
#include "sample.h"

int main()
{
    float a[8] = {18.44,14.18,19.79,15.73,15.36,16.17,13.91,15.35};
    Sample samp;
    samp.set_sample(a, 8);
    samp.display();
    std::cout << "Sample mean = " << samp.mean() << std::endl;
    std::cout << "Sample std dev = " << samp.std_dev() << std::endl;
    return 0;
}
